#include "myutils.h"

extern void dsymv_(const char *uplo, const int *N, double *alpha,
				   double *A, const int *lda, double *X, const int *incx,
				   double *beta, double *Y, const int *incy);

int main()
{
	int inc = 1;
	int N = 3;

//	char trans = 'T'; // 'No transpose', 'Transpose', 'Conjugate transpose'
	char uplo = 'L';  // 'Upper triangular', 'Lower triangular'
//	char diag = 'N';  // 'Non-unit triangular', 'Unit triangular'
//	char side = 'L';  // 'Left', 'Right'

	// Designated Initializer
	double A[9] = {8, 4, 2,
				[4] = 6, 7, 
				[8] = 3};

	// | 8.0  4.0  2.0 |
	// | 4.0  6.0  7.0 |
	// | 2.0  7.0  3.0 |

	int lda = 3;

	double X[3] = {3, 2, 1}; 
	double Y[3] = {5, 3, 2}; 

	double alpha = 1.0;
	double beta = 1.0;

	print_mat(3, 3, A);
	print_vec(3, X);
	print_vec(3, Y);

	dsymv_(&uplo, &N, &alpha, A, &lda, X, &inc, &beta, Y, &inc);

	print_vec(3, X);
	print_vec(3, Y);

	return 0;
}
