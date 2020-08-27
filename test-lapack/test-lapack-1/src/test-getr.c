#include "myutils.h"

// dgetrf computes an LU factorization of a general M by N matrix A using partial pivoting
// with row interchanges.
// The factorization has the form A = P*L*U
// where P is a permutation matrix, L is lower triangular with unit diagonal elements
// (lower trapezoidal if m>n), and U is upper traingular (upper trapezoidal if m<n).

extern void dgetrf_(const int *m, const int *n, 
					double *a, const int *lda,
					int *ipivot, int *info);

// dgetrs solves a system of linear equations A*X = B or A'*X = B with a general N by N matrix
// A using the LU factorization computed by dgetrf
extern void dgetrs_(const char *trans, const int *n, const int *nhrs, 
					const double *a, const int *lda,
					const int *ipivot, 
					double *b, const int *ldb,
					int *info);

/*
	MATLAB equivalent of A\B, where

      [ 2.3 3.2 3.4 5.5 2.0 ]         [ 2.3 ]
      [ 4.2 3.4 3.2 4.5 5.6 ]         [ 5.3 ]
  A = [ 3.4 8.5 4.3 6.5 9.9 ] ,   B = [ 6.0 ]
      [ 4.6 7.5 3.0 0.3 4.5 ]         [ 5.3 ]
      [ 0.2 4.4 2.2 5.4 2.4 ]         [ 2.4 ]

        [  1.7995 ]
        [  0.6552 ]
  A\B = [ -2.6688 ]
        [  0.9480 ]
        [ -0.0377 ]
*/

int main()
{
	int N = 5;
	double A[5*5] = {[0] = 2.3, 3.2, 3.4, 5.5, 2.0,
					[5] = 4.2, 3.4, 3.2, 4.5, 5.6, 
					[10] = 3.4, 8.5, 4.3, 6.5, 9.9,
					[15] = 4.6, 7.5, 3.0, 0.3, 4.5,
					[20] = 0.2, 4.4, 2.2, 5.4, 2.4 };

  	// in order for Fortran column-major storage
 	mtx_transpose(A, N, N);
	printm(N, N, A);

	int nrhs = 2;
	double b[5*2] = {[0] = 2.3, 5.3, 6.0, 5.3, 2.4,
					[5] = 1.0, 2.3, 2.0, 3.0, 4.0 };
	printm(N, nrhs, b);
	
	char tr = 'N';

	int lda = N;
	int ldb = N;
	int info = 0;

	int ipiv[5];

	// without calling external matrix transpose function
	// Solve the linear system
	dgetrf_(&N, &N, A, &lda, ipiv, &info);
	printm(N, N, A);
	printv(N, ipiv);

	dgetrs_(&tr, &N, &nrhs, A, &lda, ipiv, b, &ldb, &info);
	
	// Check for success
	if(info == 0)
	{
		printm(N, nrhs, b);
	}
	else
	{
		printf("dgetrs returned error %d \n", info);
	}

	return info;
}
