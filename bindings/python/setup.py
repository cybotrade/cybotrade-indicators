from setuptools import setup, Extension
from Cython.Build import cythonize
import numpy

extensions = [
    Extension(
        "cybotrade_indicators",
        sources=["external/tiamalgamation.c", "src/cybotrade_indicators/*.pyx"],
        include_dirs=["external", "src/cybotrade_indicators", numpy.get_include()]
    )
]

setup(
    ext_modules=cythonize(extensions)
)