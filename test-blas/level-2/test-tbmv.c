
#include "myutils.h"

extern void stbmv_( char *uplo, char *trans, char *diag, 
					const int *N, const int *K, 
 					float *A, const int *lda, 
					float *X, const int *incX);

int main() {

	// https://www.ibm.com/support/knowledgecenter/SSFHY8_6.2/reference/am5gr_hstbmv.html

	int one = 1;
	int lda = 4;

	int N = 4;
	int K = 3;// bandwidth = 3

	float AX[4*4] = {[3] = 1, 
					[6] = 1, 2,
					[9] = 1,2,3,1,2,3,4 };

	// | 1.0  1.0  1.0  1.0 |
	// |  .   2.0  2.0  2.0 |
	// |  .    .   3.0  3.0 |
	// |  .    .    .   4.0 |

 	char uplo = 'U';
	char trans = 'T';
	char diag = 'N';

	float X[4] = {1,2,3,4};
	
	stbmv_(&uplo, &trans, &diag, &N,  &K, &AX[0], &lda, &X[0], &one);

	PRINT_s(X, 4);


	// another example
	N = 7;
	K = 3;	// upper/lower band width of matrix A
	lda = 4;

 	uplo = 'U';
	trans = 'N';
	diag = 'N';

	// stored in AX with ku + kl + 2
	float AX7[4*7] = { [3] = 1,
					[6] = 1,2,
					[9] = 1,2,3,
					[12] = 1,2,3,4,
					[16] = 2,3,4,5,
					[20] = 3,4,5,6,
					[24] = 4,5,6,7 };

	// | 1.0  1.0  1.0  1.0  0.0  0.0  0.0 |
	// | 0.0  2.0  2.0  2.0  2.0  0.0  0.0 |
	// | 0.0  0.0  3.0  3.0  3.0  3.0  0.0 |
	// | 0.0  0.0  0.0  4.0  4.0  4.0  4.0 |
	// | 0.0  0.0  0.0  0.0  5.0  5.0  5.0 |
	// | 0.0  0.0  0.0  0.0  0.0  6.0  6.0 |
	// | 0.0  0.0  0.0  0.0  0.0  0.0  7.0 |
	
	float X7[7] = {1,2,3,4,5,6,7};
	
	stbmv_(&uplo, &trans, &diag, &N,  &K, &AX7[0], &lda, &X7[0], &one);
	PRINT_s(X7, 7);

	return 0;
}
