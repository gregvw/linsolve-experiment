# setup.py

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext
import numpy
import os


os.environ["CC"] = "g++"
os.environ["CXX"] = "g++"


setup( name = 'linsolve',
       version = '0.1',
       author = 'Greg von Winckel',
       description = 'Solve a linear system with LAPACK, called by C++, and wrapped with Cython',
       ext_modules=[Extension("cy_linsolve",
                        sources=["cy_linsolve.pyx","linsolve.cpp"],
                        language="c++",
                        include_dirs=[numpy.get_include()],
                        extra_compile_args = ['-llapack'],
                        extra_link_args = ['-llapack'],
                        )
       ],
       cmdclass = {'build_ext': build_ext},
)                                         
       
