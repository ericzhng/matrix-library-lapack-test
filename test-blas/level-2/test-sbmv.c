#include "myutils.h"

extern void dsbmv_(const char *uplo, const int *N, const int *K, double *alpha,
				   double *A, const int *lda, double *X, const int *incx,
				   double *beta, double *Y, const int *incy);

int main()
{
	int inc = 1;
	int N = 7;
	int K = 3;

//	char trans = 'T'; // 'No transpose', 'Transpose', 'Conjugate transpose'
	char uplo = 'U';  // 'Upper triangular', 'Lower triangular'
//	char diag = 'N';  // 'Non-unit triangular', 'Unit triangular'
//	char side = 'L';  // 'Left', 'Right'

	// Designated Initializer
	double A[28] = {[3] = 1,
				[6] = 1, 2, 
				[9] = 1, 2, 3,
				[12] = 1, 2, 3, 4,
				[16] = 2, 3, 4, 5, 3, 4, 5, 6, 4, 5, 6, 7};
	
	// | 1.0  1.0  1.0  1.0  0.0  0.0  0.0 |
	// | 1.0  2.0  2.0  2.0  2.0  0.0  0.0 |
	// | 1.0  2.0  3.0  3.0  3.0  3.0  0.0 |
	// | 1.0  2.0  3.0  4.0  4.0  4.0  4.0 |
	// | 0.0  2.0  3.0  4.0  5.0  5.0  5.0 |
	// | 0.0  0.0  3.0  4.0  5.0  6.0  6.0 |
	// | 0.0  0.0  0.0  4.0  5.0  6.0  7.0 |
		
// 		   |  .    .    .   1.0  2.0  3.0  4.0 |
//         |  .    .   1.0  2.0  3.0  4.0  5.0 |
// A    =  |  .   1.0  2.0  3.0  4.0  5.0  6.0 |
//         | 1.0  2.0  3.0  4.0  5.0  6.0  7.0 |								

	int lda = 4;

	double X[7] = {1, 2, 3, 4, 5, 6, 7}; 
	double Y[7] = {1, 2, 3, 4, 5, 6, 7}; 

	double alpha = 2.0;
	double beta = 10.0;

	print_mat(4, 7, A);
	print_vec(N, X);
	print_vec(N, Y);

	dsbmv_(&uplo, &N, &K, &alpha, A, &lda, X, &inc, &beta, Y, &inc);

	print_vec(N, X);
	print_vec(N, Y);

	return 0;
}
