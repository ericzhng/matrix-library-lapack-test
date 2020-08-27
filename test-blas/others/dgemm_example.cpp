#include "lapack_c_interface.h"
#include "utils.h"

// dgesv
extern "C" {

	// degmv performs one of the matrix-vector operations
	// y = alpha*A*x + beta*y, or y = alpha*A'*x + beta*y, where alpha and beta are scalars,
	// x and y are vectors and A is an m by n matrix.                                              
	void dgemv_(const char* trans, int* m, int* n, double* alpha, double* a, const int* lda, 
		double* x, int* incx, double* beta, double* y, int* incy);

	// dgemm performs one of the matrix-matrix operations
	// C = alpha*op(A)*op(B) + beta*C, where op(X) is one of op(X) = X or op(X) = X',
	// alpha and beta are scalars, and A, B and C are matrices, with op(A) an m by k matrix,
	// op(B) a k by n matrix and C an m by n matrix.
	void dgemm_(const char* transa, const char* transb, int* m, int* n, int* k, double* alpha, 
		double* a, int* lda, double* b, const int* ldb, double* beta, double* c, int* ldc);
}

/*
	MATLAB equivalent of A*B, where

       [ 2.3 3.2 3.4 5.5 2.0 2.1 ]
       [ 4.2 3.4 3.2 4.5 5.6 5.5 ]
   A = [ 3.4 8.5 4.3 6.5 9.9 9.2 ]
       [ 4.6 7.5 3.0 0.3 4.5 4.4 ]
       [ 0.2 4.4 2.2 5.4 2.4 2.1 ]

       [ 2.3 3.2 3.4 5.5 2.0 2.1 1.1 ]
       [ 4.2 3.4 3.2 4.5 5.6 5.5 4.5 ]
   B = [ 3.4 8.5 4.3 6.5 9.9 9.2 8.2 ]
       [ 4.6 7.5 3.0 0.3 4.5 4.4 3.4 ]
       [ 0.2 4.4 2.2 5.4 2.4 2.1 1.1 ]
       [ 1.2 5.4 3.2 6.4 3.4 3.1 1.1 ]

             [  58.51 108.53  60.30  75.04  92.87  88.62  68.02 ]
             [  63.24 140.29  82.34 125.99 111.51 105.57  73.67 ]
   C = A*B = [ 101.06 218.32 127.97 199.19 181.26 171.36 120.36 ]
             [  59.84 111.53  77.42 131.10 108.01 102.92  74.22 ]
             [  54.26  96.70  52.42  63.22  84.02  80.17  61.37 ]
*/

int main()
{
	int i, j;
	char no = 'N', tr = 'T';
	int m = 5, k = 6, n = 7;
	double alpha = 1.0, beta = 0.0;
	double **a, **b, **c;
	int lda = n, ldb = k, ldc = n;

	// a[n][n] contiguous 2d array
	a = dmatrix_malloc(m, k);
	b = dmatrix_malloc(k, n);
	c = dmatrix_malloc(m, n);

	// populate matrix a 
	a[0][0]=2.3; a[0][1]=3.2; a[0][2]=3.4; a[0][3]=5.5; a[0][4]=2.0; a[0][5]=2.1; 
	a[1][0]=4.2; a[1][1]=3.4; a[1][2]=3.2; a[1][3]=4.5; a[1][4]=5.6; a[1][5]=5.5; 
	a[2][0]=3.4; a[2][1]=8.5; a[2][2]=4.3; a[2][3]=6.5; a[2][4]=9.9; a[2][5]=9.2; 
	a[3][0]=4.6; a[3][1]=7.5; a[3][2]=3.0; a[3][3]=0.3; a[3][4]=4.5; a[3][5]=4.4;
	a[4][0]=0.2; a[4][1]=4.4; a[4][2]=2.2; a[4][3]=5.4; a[4][4]=2.4; a[4][5]=2.1;

	// populate matrix a
	b[0][0]=2.3; b[0][1]=3.2; b[0][2]=3.4; b[0][3]=5.5; b[0][4]=2.0; b[0][5]=2.1; b[0][6]=1.1;
	b[1][0]=4.2; b[1][1]=3.4; b[1][2]=3.2; b[1][3]=4.5; b[1][4]=5.6; b[1][5]=5.5; b[1][6]=4.5;
	b[2][0]=3.4; b[2][1]=8.5; b[2][2]=4.3; b[2][3]=6.5; b[2][4]=9.9; b[2][5]=9.2; b[2][6]=8.2;
	b[3][0]=4.6; b[3][1]=7.5; b[3][2]=3.0; b[3][3]=0.3; b[3][4]=4.5; b[3][5]=4.4; b[3][6]=3.4;
	b[4][0]=0.2; b[4][1]=4.4; b[4][2]=2.2; b[4][3]=5.4; b[4][4]=2.4; b[4][5]=2.1; b[4][6]=1.1;
	b[5][0]=1.2; b[5][1]=5.4; b[5][2]=3.2; b[5][3]=6.4; b[5][4]=3.4; b[5][5]=3.1; b[5][6]=1.1;

	print_dmatrix(a, m, k);
	print_dmatrix(b, k, n);

	// matrix-vector product
	dgemm_(&no, &no, &n, &m, &k, &alpha, &b[0][0], &lda, &a[0][0], &ldb, &beta, &c[0][0], &ldc);

	print_dmatrix(c, m, n);

	dmatrix_dealloc(a);
	dmatrix_dealloc(b);
	dmatrix_dealloc(c);
	return 0;
}
