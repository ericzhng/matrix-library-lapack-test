
#include "myutils.h"

extern void dger_( //char *uplo, char *trans, char *diag, 
					const int *M, const int *N, double *alpha,
					double *X, const int *incX,
					double *Y, const int *incY,
 					double *A, const int *lda );

int main() {

	int one = 1;
	int two = 2;

	int M = 4;
	int N = 3;

	int lda = 10;

	// Matrix A:
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

	double A[10 * 3] = {[1] = 1,2,3,4, [10] = 0.0, 
					[11] = 2,2,2,2,
					[21] = 3,4,2,1};

	double alpha = 1.0;

	double X[4] = { 3, 2, 1, 4};
	double Y[2*3-1] = {1, 0, 2, 0, 3};

	print_mat(10, 3, A);

	dger_(&M, &N, &alpha, X, &one, Y, &two, &A[1], &lda);

	print_mat(10, 3, A);
	print_vec(10, X);
	print_vec(5, Y);
	
	return 0;
}
