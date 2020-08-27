
#include "../myutils.h"

extern void stpsv_( char *uplo, char *trans, char *diag, 
					const int *N, 
 					float *Ap,
					float *X, const int *incX);

int main() {

	int one = 1;
	int N = 4;

	float AP[10] = {1, 2, 2, 3, 2, 3, 2, 5, 3, 1};
	// | 1.0  2.0  3.0  2.0 |
	// |  .   2.0  2.0  5.0 |
	// |  .    .   3.0  3.0 |
	// |  .    .    .   1.0 |
	
 	char uplo = 'U';
	char trans = 'T';
	char diag = 'N';

	float X[4] = {5, 18, 32, 41};
	
	stpsv_(&uplo, &trans, &diag, &N, &AP[0], &X[0], &one);
	
	PRINT_s(X, N);

	return 0;
}
