use std::{
    borrow::Borrow,
    collections::HashSet,
    env,
    ffi::OsStr,
    path::{Path, PathBuf},
    process::Command,
};

fn run_command_or_fail<P, S>(dir: &str, cmd: P, args: &[S])
where
    P: AsRef<Path>,
    S: Borrow<str> + AsRef<OsStr>,
{
    let cmd = cmd.as_ref();
    let cmd = if cmd.components().count() > 1 && cmd.is_relative() {
        // If `cmd` is a relative path (and not a bare command that should be
        // looked up in PATH), absolutize it relative to `dir`, as otherwise the
        // behavior of std::process::Command is undefined.
        // https://github.com/rust-lang/rust/issues/37868
        PathBuf::from(dir)
            .join(cmd)
            .canonicalize()
            .expect("canonicalization failed")
    } else {
        PathBuf::from(cmd)
    };
    eprintln!(
        "Running command: \"{} {}\" in dir: {}",
        cmd.display(),
        args.join(" "),
        dir
    );
    let ret = Command::new(cmd).current_dir(dir).args(args).status();
    match ret.map(|status| (status.success(), status.code())) {
        Ok((true, _)) => (),
        Ok((false, Some(c))) => panic!("Command failed with error code {}", c),
        Ok((false, None)) => panic!("Command got killed"),
        Err(e) => panic!("Command failed with error: {}", e),
    }
}

// The directory for the indicators library.
const INDICATORS_PATH: &'static str = "../../";

fn main() {
    // eprintln!("Setting up submodules");
    // run_command_or_fail("./", "git", &["submodule", "update", "--init"]);
    // eprintln!("Building and linking indicators statically");

    let out_dir = env::var("OUT_DIR").expect("OUT_DIR missing");

    // Copy the C library to output directory
    run_command_or_fail(
        ".",
        "cp",
        &["-a", &format!("{}/.", INDICATORS_PATH), &out_dir],
    );

    // Build the C library (indicators)
    println!("Building indicators");
    run_command_or_fail(&out_dir, "make", &["all"]);

    // Tell cargo to look for built libraries in the specified directory
    println!("cargo:rustc-link-search=native={}", out_dir);
    // Tell cargo to tell rustc to link our library. Cargo will
    // automatically know it must look for a `libindicators.a` file.
    println!("cargo:rustc-link-lib=static=indicators");
    println!("cargo:root={}", out_dir);

    // Ignore some of the generated enums.
    let ignored_macros = IgnoreMacros(
        vec![
            "FP_INFINITE".into(),
            "FP_NAN".into(),
            "FP_NORMAL".into(),
            "FP_SUBNORMAL".into(),
            "FP_ZERO".into(),
        ]
        .into_iter()
        .collect(),
    );

    // The bindgen::Builder is the main entry point
    // to bindgen, and lets you build up options for
    // the resulting bindings.
    let bindings = bindgen::Builder::default()
        // The input header we would like to generate
        // bindings for.
        .header(format!("{}/indicators.h", INDICATORS_PATH))
        // Tell cargo to invalidate the built crate whenever any of the
        // included header files changed.
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        // Tell cargo to ignore some of the generated enums.
        .parse_callbacks(Box::new(ignored_macros))
        // Format the generated bindings with rustfmt.
        .formatter(bindgen::Formatter::Rustfmt)
        // Finish the builder and generate the bindings.
        .generate()
        // Unwrap the Result and panic on failure.
        .expect("Unable to generate bindings");

    // Write the bindings to the $OUT_DIR/bindings.rs file.
    let out_path = PathBuf::from(out_dir);
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}

#[derive(Debug)]
struct IgnoreMacros(HashSet<String>);

impl bindgen::callbacks::ParseCallbacks for IgnoreMacros {
    fn will_parse_macro(&self, name: &str) -> bindgen::callbacks::MacroParsingBehavior {
        if self.0.contains(name) {
            bindgen::callbacks::MacroParsingBehavior::Ignore
        } else {
            bindgen::callbacks::MacroParsingBehavior::Default
        }
    }
}
