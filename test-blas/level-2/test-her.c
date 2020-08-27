
#include "../myutils.h"

extern void dger_( //char *uplo, char *trans, char *diag, 
					const int *M, const int *N, double *alpha,
					double *X, const int *incX,
					double *Y, const int *incY,
 					double *A, const int *lda );

int main() {

	int one = 1;
	int lda = 3;

	int M = 3;
	int N = 3;

	// Matrix A is a real 4 by 4 lower unit triangular matrix
	double A[3*3] = {[0] = 2, 3, 1, 
					[3] = 3, 1, 2,
					[6] = 1, 2, 1 };

	//         | 2.0  3.0  1.0  |
	// A    =  | 3.0  1.0  2.0  |
	//         | 1.0  2.0  1.0  |

	// 	char uplo = 'L';
	//	char trans = 'N';
	//	char diag = 'U';

	double alpha = 1.0;
	double X[3] = {1, 2, 3};
	double Y[3] = {2, 3, 1};

	dger_(&M, &N, &alpha, X, &one, Y, &one, A, &lda);

	printd_mat("A", 3, 3, A);

	return 0;
}
