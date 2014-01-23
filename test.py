import numpy as np
import cy_linsolve as cy
import sys

if __name__ == '__main__':

    n = int(sys.argv[1])

    A = np.random.randn(n,n)
    b = np.random.randn(n)

    x_np = np.linalg.solve(A,b)
    x_cy = cy.py_linsolve(A,b)

    print('Numpy result')
    print(x_np)
    print('LAPACK, C++, and Cython Result')
    print(x_cy)



