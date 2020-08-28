
#include "myutils.h"

// this means matrix A is saved in the format of banded format
extern void dgbmv_(const char *, const int *M, const int *N, const int *KL, const int *KU,
				   double *alpha, double *A, const int *lda, double *X, const int *incx,
				   double *beta, double *Y, const int *incy);

int main()
{

	int inc = 1;

	char trans = 'N'; // 'No transpose', 'Transpose', 'Conjugate transpose'
					  //	char uplo = 'L';	// 'Upper triangular', 'Lower triangular'
					  //	char diag = 'N';	// 'Non-unit triangular', 'Unit triangular'
					  //	char side = 'L';	// 'Left', 'Right'

	//	srand(time(NULL));

	// | 1.0  1.0  1.0  0.0 |
	// | 2.0  2.0  2.0  2.0 |
	// | 3.0  3.0  3.0  3.0 |
	// | 4.0  4.0  4.0  4.0 |
	// | 0.0  5.0  5.0  5.0 |
	
	int M = 5, N = 4;
	
	// general band matrix
	double A[6 * 4] = {[2] = 1, 2, 3, 4,
					   [7] = 1, 2, 3, 4, 5,
					   [12] = 1, 2, 3, 4, 5,
					   [18] = 2, 3, 4, 5};

	print_mat(6, 4, &A[0]);

	int kl = 3;
	int ku = 2;

	//	int lda = kl+ku+1;
	int lda = 6;

	double X[4] = {1, 2, 3, 4};
	double Y[5] = {1, 2, 3, 4, 5};

	double alpha = 2.0;
	double beta = 10.0;

	dgbmv_(&trans, &M, &N, &kl, &ku, &alpha, A, &lda, X, &inc, &beta, Y, &inc);
	
	print_vec(5, &Y[0]);

	return 0;
}
