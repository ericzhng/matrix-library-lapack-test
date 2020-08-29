
#include "myutils.h"

extern void sgemv_(const char *, const int *M, const int *N, float *alpha,
				   float *A, const int *lda, float *X, const int *incx,
				   float *beta, float *Y, const int *incy);

extern void dgemv_(const char *, const int *M, const int *N, double *alpha,
				   double *A, const int *lda, double *X, const int *incx,
				   double *beta, double *Y, const int *incy);


// this examples refers to https://www.ibm.com/support/knowledgecenter/SSFHY8_6.2/reference/am5gr_hsgemv.html

int main()
{
	int incx = 1;
	int incy = 2;
	const int M1 = 4;
	const int N = 3;
	int lda = 10;

	char trans = 'N'; // 'No transpose', 'Transpose', 'Conjugate transpose'
	// char uplo = 'L';  // 'Upper triangular', 'Lower triangular'
	// char diag = 'N';  // 'Non-unit triangular', 'Unit triangular'
	// char side = 'L';  // 'Left', 'Right'

	// Matrix Af:
	// |  .    .    .  |
    // | 1.0  2.0  3.0 |
    // | 2.0  2.0  4.0 |
    // | 3.0  2.0  2.0 |
    // | 4.0  2.0  1.0 |
	// |  .    .    .  |
	// |  .    .    .  |
	// |  .    .    .  |
	// |  .    .    .  |
	// |  .    .    .  |

	float Af[10 * 3] = {[1] = 1,2,3,4, [10] = 0.0, 
					[11] = 2,2,2,2,
					[21] = 3,4,2,1};

	float alphaf = 1.0;
	float betaf = 1.0;

	float Xf[3] = {3,2,1};
	float Yf[2*4-1] = {4, 0, 5, 0, 2, 0, 3};
	int yn = 2*4-1;
	print_vec(yn, Yf);

	sgemv_(&trans, &M1, &N, &alphaf, &Af[1], &lda, Xf, &incx, &betaf, Yf, &incy);

	print_mat(10, N, Af);
	print_vec(N, Xf);
	print_vec(yn, Yf);


	// random matrix, another example
	// srand(time(NULL));
	const int M = 10;

	double A[M * N];
	set_random(A, M, N);

	double X[N];
	set_random(X, N, 1);
	double Y[M];
	set_random(Y, M, 1);

	double alpha = 1.0;
	double beta = 1.0;

	print_mat(10, N, A);
	print_vec(N, X);
	print_vec(M, Y);

	int inc = 1;

	dgemv_(&trans, &M, &N, &alpha, A, &lda, X, &inc, &beta, Y, &inc);

	print_vec(N, X);
	print_vec(M, Y);

	return 0;
}
