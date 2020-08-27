
#include "../myutils.h"

// this means matrix A is saved in the format of banded format
extern void chemv_(const char *uplo, const int *N, const complex *alpha, 
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

	// https://www.ibm.com/support/knowledgecenter/SSFHY8_6.2/reference/am5gr_hsslmx.html

	int N = 3;
	complex A[9] = { [0] = {1, 0},{3, -5},{2, 3},
					 [4] = {7, 0},{4, 8},
					 [8] = {6, 0}};
	
	// 	       | (1.0,  . )       .          .      |
	// A    =  | (3.0, -5.0)  (7.0, .  )     .      |
	//         | (2.0,  3.0)  (4.0, 8.0) (6.0,  . ) |

	printc_mat("A", 3, 3, A);

	complex X[3] = {{1,2}, {4, 0}, {3, 4}};
	complex Y[3] = {{1,0}, {2, -1}, {2, 1}};

	complex beta = {1, 0};
	complex alpha = {1, 0};

	int lda = 3;

	chemv_(&uplo, &N, &alpha, A, &lda, X, &inc, &beta, Y, &inc);

	printc_vec("Y", 3, Y);

	return 0;
}
