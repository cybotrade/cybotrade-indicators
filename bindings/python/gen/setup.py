from setuptools import setup, Extension
from Cython.Build import cythonize

extensions = [
    Extension(
        name='cybotrade_indicators_gen',
        sources=['../external/tiamalgamation.c', 'cybotrade_indicators_gen.pyx'],
        include_dirs=['../external'],
    )
]

setup(
    ext_modules=cythonize(extensions)
)