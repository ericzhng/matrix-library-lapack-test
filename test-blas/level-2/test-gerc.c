
#include "myutils.h"

extern void cgerc_( //char *uplo, char *trans, char *diag, 
					const int *M, const int *N, complex *alpha,
					complex *X, const int *incX,
					complex *Y, const int *incY,
 					complex *A, const int *lda );

int main() {

	int one = 1;
	int lda = 3;

	int M = 3;
	int N = 3;

	// Matrix A is a real 4 by 4 lower unit triangular matrix
	complex A[3*3] = {[0] ={1,1},  {2,2},  {3,3}, 
					[3] =  {2,1},  {2,2},  {2,3},
					[6] =  {2,4},  {1,5},  {1,2} };

	//         | 2.0  3.0  1.0  |
	// A    =  | 3.0  1.0  2.0  |
	//         | 1.0  2.0  1.0  |

// 	char uplo = 'L';
//	char trans = 'N';
//	char diag = 'U';

	complex alpha = {1.0, 0.0};
	complex X[3] = {{1,1}, {2,2}, {1,2}};
	complex Y[3] = {{1,1}, {3,3}, {1,2}};
	
	cgerc_(&M, &N, &alpha, X, &one, Y, &one, A, &lda);

	print_mat(3, 3, &A[0]);

	return 0;
}
