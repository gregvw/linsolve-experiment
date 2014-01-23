# distutils: language = c++
# distutils: sources = linsolve.cpp

import cython 
import numpy as np
cimport numpy as np

cdef extern from "linsolve.hpp":
    int linsolve(int,double*, double*, double*)

def py_linsolve(np.ndarray[np.double_t,ndim=2] A,
                np.ndarray[np.double_t,ndim=1] b):

    cdef np.ndarray[np.double_t,ndim=1] x
    cdef np.ndarray[np.double_t,ndim=1] avec
    cdef int foo

    avec = A.flatten("F")
    x = np.zeros(b.size,np.double)
     
    foo = linsolve(b.size,<double*> avec.data, <double*> x.data, <double*> b.data)
    return x

