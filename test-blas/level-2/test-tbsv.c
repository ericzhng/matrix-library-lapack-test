
#include "../myutils.h"

extern void stbsv_( char *uplo, char *trans, char *diag, 
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
					[6] = 2, 2,
					[9] = 3,2,3, 
					[12] = 2,5,3,1 };
	
	// upper-triangular-band-packed storage mode
	// A    =  |  .    .    .   2.0 |
    //         |  .    .   3.0  5.0 |
    //         |  .   2.0  2.0  3.0 |
    //         | 1.0  2.0  3.0  1.0 |

	// Matrix A is a real 4 by 4 upper triangular band matrix with an upper band width of 3
	// | 1.0  2.0  3.0  2.0 |
	// | 0.0  2.0  2.0  5.0 |
	// | 0.0  0.0  3.0  3.0 |
	// | 0.0  0.0  0.0  1.0 |
	
 	char uplo = 'U';
	char trans = 'T';
	char diag = 'N';

	float X[4] = {5, 18, 32, 41};
	
	stbsv_(&uplo, &trans, &diag, &N, &K, &AX[0], &lda, &X[0], &one);

	PRINT_s(X, 4);

	return 0;
}
