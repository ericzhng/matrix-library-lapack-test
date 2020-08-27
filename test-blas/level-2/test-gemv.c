#include "../myutils.h"

extern void sgemv_(const char *, const int *M, const int *N, float *alpha,
				   float *A, const int *lda, float *X, const int *incx,
				   float *beta, float *Y, const int *incy);

extern void dgemv_(const char *, const int *M, const int *N, double *alpha,
				   double *A, const int *lda, double *X, const int *incx,
				   double *beta, double *Y, const int *incy);

int main()
{
	int inc = 1;

	char trans = 'N'; // 'No transpose', 'Transpose', 'Conjugate transpose'
//	char uplo = 'L';  // 'Upper triangular', 'Lower triangular'
//	char diag = 'N';  // 'Non-unit triangular', 'Unit triangular'
//	char side = 'L';  // 'Left', 'Right'

	// https://www.ibm.com/support/knowledgecenter/SSFHY8_6.2/reference/am5gr_hsgemv.html

	float Af[5 * 3] = {[1] = 1,2,3,4,
						[6] = 2,2,2,2,
						[11] = 3,4,2,1};

	// |  .    .    .  |
    // | 1.0  2.0  3.0 |
    // | 2.0  2.0  4.0 |
    // | 3.0  2.0  2.0 |
    // | 4.0  2.0  1.0 |

	int ldaF = 5;

	printf_mat("Af", 5, 3, Af);

	float Xf[3] = {3,2,1};
	float Yf[4] = {4,5,2,3};

	float alphaf = 1.0;
	float betaf = 1.0;

	int M1 = 4, N1 = 3;

	sgemv_(&trans, &M1, &N1, &alphaf, &Af[1], &ldaF, Xf, &inc, &betaf, Yf, &inc);

	printf_vec("Yf", M1, Yf);



	// random matrix, another example
	//	srand(time(NULL));
	int M = 5, N = 5;

	double A[M * N];
	init(A, M, N);

	int lda = M;

	double X[M];
	init(X, M, 1);
	double Y[M];
	init(Y, M, 1);

	double alpha = 1.0;
	double beta = 2.0;

	printd_mat("A", M, N, A);
	printd_vec("X", M, X);
	printd_vec("Y", M, Y);

	dgemv_(&trans, &M, &N, &alpha, A, &lda, X, &inc, &beta, Y, &inc);

	printd_vec("X", M, X);
	printd_vec("Y", M, Y);

	return 0;
}
