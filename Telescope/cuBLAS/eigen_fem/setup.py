from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize
from Cython.Distutils import build_ext
import numpy

setup(
  ext_modules = cythonize(
    Extension(
      "model_wrapper", 
      [ "model_wrapper.pyx", "model.cpp" ], 
      include_dirs=[
        numpy.get_include(),
        './Eigen'
        ],
      language="c++",
    ),
    annotate=True,
  ),
  cmdclass = {
    'build_ext': build_ext
  }
)