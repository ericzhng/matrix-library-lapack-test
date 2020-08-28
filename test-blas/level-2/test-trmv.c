
#include "myutils.h"

extern void strmv_( char *uplo, char *trans, char *diag, 
					const int *N, 
 					float *A, const int *lda, 
					float *X, const int *incX);

int main() {

	int one = 1;
	int lda = 4;

	int N = 4;

	float AX[4*4] = {[0] = 1, 
					[4] = 2, 2,
					[8] = 3,3,3,
					[12] = 2,5,3,1 };

	// | 1.0  1.0  1.0  1.0 |
	// |  .   2.0  2.0  2.0 |
	// |  .    .   3.0  3.0 |
	// |  .    .    .   4.0 |

 	char uplo = 'U';
	char trans = 'T';
	char diag = 'N';

	float X[4] = {5, 4, 3, 2};
	
	strmv_(&uplo, &trans, &diag, &N, &AX[0], &lda, &X[0], &one);
	
	PRINT_s(X, 4);


	return 0;
}
