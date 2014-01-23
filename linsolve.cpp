#include<iostream>
#include"lapacke.h"
#include"linsolve.hpp"

int linsolve(int N,double* A, double* X, double* B)
{
    char TRANS = 'N';
    int  INFO  = N;
    int  LDA   = N;
    int  LDB   = N;
    int  NRHS  = 1;
    int*  IPIV  = new int[N];

    int i;
    for(i=0;i<N;i++)
    {
        X[i]=B[i];
    }

    LAPACK_dgetrf(&N,&N,A,&LDA,IPIV,&INFO);

    dgetrs_(&TRANS,&N,&NRHS,A,&LDA,IPIV,X,&LDB,&INFO);

    delete IPIV;    
}


/*
int main()
{
    using namespace std;

    int N = 4;
    double* A = new double[N*N];
    double* X = new double[N];
    double* B = new double[N];

    A[0] = 2;    A[1] = -1;    A[2] = 0;     A[3] = 0;
    A[4] = -1;   A[5] = 2;     A[6] = -1;    A[7] = 0;
    A[8] = 0;    A[9] = -1;    A[10] = 2;    A[11] = -1;
    A[12] = 0;   A[13] = 0 ;   A[14] = -1;   A[15] = 2;

    B[0] = 1;    B[1] = 1;     B[2] = 1;     B[3] = 1;

    linsolve(A,X,B,N);

    int i;
    for(i=0;i<N;i++)
    {
        cout << X[i] << endl;
    }

    delete A,X,B;
    return 0;
}*/
