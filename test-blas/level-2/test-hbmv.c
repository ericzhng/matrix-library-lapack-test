
#include "../myutils.h"

// this means matrix A is saved in the format of banded format
extern void chbmv_(const char *uplo, const int *N, const int *K, const complex *alpha, 
				const complex *A, const int *lda,
				const complex *X, const int *incX, const complex *beta, 
				const complex *Y, const int *incY);

// FORTRAN adds _ after all the function names
// and all variables are called by reference

int main()
{
	int inc = 1;

//	char trans = 'N'; // 'No transpose', 'Transpose', 'Conjugate transpose'
	char uplo = 'L';  // 'Upper triangular', 'Lower triangular'
//	char diag = 'N';  // 'Non-unit triangular', 'Unit triangular'
//	char side = 'L';  // 'Left', 'Right'

	//	srand(time(NULL));

	int N = 7;
	complex A[4*7]= {{1, 0},{1, 1},{1, 1},{1, 1},
					 {2, 0},{2, 2},{2, 2},{2, 2},
					 {3, 0},{3, 3},{3, 3},{3, 3},
					 {4, 0},{4, 4},{4, 4},{4, 4},
					 [16] = {5, 0},{5, 5},{5, 5},
					 [20] = {6, 0},{6, 6},
					 [24] = {7, 0} };

	// |  (1.0, 0.0)  (1.0, 1.0)  (1.0, 1.0)  (1.0, 1.0)  (0.0, 0.0)  (0.0, 0.0)  (0.0, 0.0) |
	// | (1.0, -1.0)  (2.0, 0.0)  (2.0, 2.0)  (2.0, 2.0)  (2.0, 2.0)  (0.0, 0.0)  (0.0, 0.0) |
	// | (1.0, -1.0) (2.0, -2.0)  (3.0, 0.0)  (3.0, 3.0)  (3.0, 3.0)  (3.0, 3.0)  (0.0, 0.0) |
	// | (1.0, -1.0) (2.0, -2.0) (3.0, -3.0)  (4.0, 0.0)  (4.0, 4.0)  (4.0, 4.0)  (4.0, 4.0) |
	// |  (0.0, 0.0) (2.0, -2.0) (3.0, -3.0) (4.0, -4.0)  (5.0, 0.0)  (5.0, 5.0)  (5.0, 5.0) |
	// |  (0.0, 0.0)  (0.0, 0.0) (3.0, -3.0) (4.0, -4.0) (5.0, -5.0)  (6.0, 0.0)  (6.0, 6.0) |
	// |  (0.0, 0.0)  (0.0, 0.0)  (0.0, 0.0) (4.0, -4.0) (5.0, -5.0) (6.0, -6.0)  (7.0, 0.0) | 

	//         |  (1.0, . )  (2.0, . )  (3.0, . )  (4.0, . )  (5.0, . )  (6.0, . ) (7.0, . ) |
	//         | (1.0, 1.0) (2.0, 2.0) (3.0, 3.0) (4.0, 4.0) (5.0, 5.0) (6.0, 6.0)     .     |
	// A    =  | (1.0, 1.0) (2.0, 2.0) (3.0, 3.0) (4.0, 4.0) (5.0, 5.0)   .            .     |
	//         | (1.0, 1.0) (2.0, 2.0) (3.0, 3.0) (4.0, 4.0)   .          .            .     |

	printc_mat("A", 4, 7, A);

	complex X[7] = {{1,1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}};
	complex Y[7] = {{1,1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}};

	complex alpha = {2, 0};
	complex beta = {10, 0};

	int lda = 4;
	int K = 3;

	chbmv_(&uplo, &N, &K, &alpha, A, &lda, X, &inc, &beta, Y, &inc);

	printc_vec("Y", 7, Y);

	return 0;
}
