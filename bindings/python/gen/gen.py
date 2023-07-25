import argparse
import os

from cybotrade_indicators_gen import gen


def main():
    parser = argparse.ArgumentParser(description='Generate cybotrade indicators')
    parser.add_argument('--output-dir', type=str, default='.',
                        help='destination for generated indicators module')

    args = parser.parse_args()

    with open(os.path.join(args.output_dir, '__init__.pyx'), 'w') as lib_pyx:
        with open(os.path.join(args.output_dir, '__init__.pyi'), 'w') as lib_pyi:
            gen(lib_pyx, lib_pyi)


if __name__ == '__main__':
    main()