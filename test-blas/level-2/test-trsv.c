
#include "myutils.h"

extern void strsv_( char *uplo, char *trans, char *diag, 
					const int *N, 
 					float *A, const int *lda, 
					float *X, const int *incX);

int main() {

	int one = 1;
	int lda = 4;

	int N = 4;

	// Matrix A is a real 4 by 4 lower unit triangular matrix
	float AX[4*4] = {[1] = 1, 2, 3, 
					[6] = 3, 4,
					[11] = 3 };

	//         |  .    .    .   . |
	//         | 1.0   .    .   . |
	// A    =  | 2.0  3.0   .   . |
	//         | 3.0  4.0  3.0  . |

 	char uplo = 'L';
	char trans = 'N';
	char diag = 'U';

	float X[4] = {1, 3, 11, 24};
	strsv_(&uplo, &trans, &diag, &N, &AX[0], &lda, &X[0], &one);
	PRINT_s(X, 4);



	float AX2[4*4] = {[0] = 1, 
					[4] = 2,2,
					[8] = 3,2,3,
					[12] = 2,5,3,1 };

	//         | 1.0  2.0  3.0  2.0 |
	// A    =  |  .   2.0  2.0  5.0 |
	//         |  .    .   3.0  3.0 |
	//         |  .    .    .   1.0 |

	uplo = 'U';
	trans = 'T';
	diag = 'N';

	float X2[4] = {5, 18, 32, 41};
	strsv_(&uplo, &trans, &diag, &N, &AX2[0], &lda, &X2[0], &one);
	PRINT_s(X2, 4);

	return 0;
}
