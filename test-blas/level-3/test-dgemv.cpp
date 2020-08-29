#include <stdio.h>
#include <iostream>     // std::cout

void print_mat_double(const char *name, int row, int column, double *A)
{
    printf(" == Matrix %s (%d X %d): == \n", name, row, column);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf(" %.5f  ", A[j * row + i]);
        }
        printf("\n");
    }
    printf("\n");
}
#define print_mat(row, column, A) print_mat_double(#A, row, column, A)

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

      [ 2.3 3.2 3.4 5.5 2.0 2.1 ]         [ 2.3 ]
      [ 4.2 3.4 3.2 4.5 5.6 5.5 ]         [ 5.3 ]
  A = [ 3.4 8.5 4.3 6.5 9.9 9.2 ] ,   B = [ 6.0 ]
      [ 4.6 7.5 3.0 0.3 4.5 4.4 ]         [ 5.3 ]
      [ 0.2 4.4 2.2 5.4 2.4 2.1 ]         [ 2.4 ]
                                          [ 3.2 ]

        [ 83.32  ]
        [ 101.77 ]
  A*B = [ 166.32 ]
        [ 94.80  ]
        [ 78.08  ]
*/

int main()
{
	char tr = 'T';

	int m = 5, n = 6;

	double alpha = 1.0, beta = 0.0;
	
	int lda = n, incx = 1, incy = 1;

	double x[6] = {2.3, 5.3, 6.0, 5.3, 2.4, 3.2};
	double y[5] = {0.0};

	// populate matrix a
	double a[5][6] = {{2.3, 3.2, 3.4, 5.5, 2.0, 2.1},
				{4.2, 3.4, 3.2, 4.5, 5.6, 5.5},
				{3.4, 8.5, 4.3, 6.5, 9.9, 9.2},
				{4.6, 7.5, 3.0, 0.3, 4.5, 4.4},
				{0.2, 4.4, 2.2, 5.4, 2.4, 2.1} };

	print_mat(m, n, a[0]);
	print_mat(n, 1, x);

	// matrix-vector product
	dgemv_(&tr, &n, &m, &alpha, &a[0][0], &lda, x, &incx, &beta, y, &incy);

	print_mat(m, 1, y);

	return 0;
}
