# indicators

This library is basically a Rust wrapper for the C library [tulipindicators](https://bitbucket.org/balaena-quant/tulipindicators/). Hence, for a detailed list of what indicators are currently supported, take a look at [tulipindicators](https://bitbucket.org/balaena-quant/tulipindicators/)'s README.

This library uses Rust's [bindgen](https://github.com/rust-lang/rust-bindgen) crate to generate Rust bindings from the C library's header files. Therefore, in order to run this library there are a few requirements to fulfill.

#### 1. Build tools for [tulipindicators](https://bitbucket.org/balaena-quant/tulipindicators/)

Since the library is written in C99 with no dependencies, there's no additional libraries needed to build it. Hence, only `gcc` and `GNU Make` are needed to build the library.

The build script can be found in `build.rs`
```rs
// equivalent to running `make` in the `tulipindicators/` directory.
Command::new("make")
  .arg("all")
  .current_dir(TULIP_INDICATORS_PATH)
  .spawn()
  .expect("Failed to run make");
```

#### 2. Dependencies for [bindgen](https://github.com/rust-lang/rust-bindgen)

A detailed description can be found at [the official requirements for bindgen](https://rust-lang.github.io/rust-bindgen/requirements.html). 

The `bindgen` crate leverages `libclang` to preprocess, parse, and type check C and C++ header files. Therefore, it is required to use Clang 5.0 or greater.

##### macOS
If you use Homebrew:

```sh
$ brew install llvm
```

If you use MacPorts:

```sh
$ port install clang
```

##### Debian-based Linuxes

```sh
$ apt install llvm-dev libclang-dev clang
```

Ubuntu 18.04 provides the necessary packages directly.

### Code samples 

This section still needs to be polished as there's no concrete examples now.

```rs
// not valid yet
fn main() {
  bq_indicators::ti_sma();
}
```
