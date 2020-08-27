
#include "../myutils.h"

extern void sspmv_( char *uplo, const int *N, const float *alpha, float *AP, float *X,
                	const int *incX, const float *beta, float *Y, const int *incY);

// extern void ssyr_( char *uplo, const int *N, const float *alpha, float *X, const int *incX,
// 					float *AP, const int *lda);

// extern void sspr_( char *uplo, const int *N, const float *alpha, float *X, const int *incX,
// 					float *AP);

// extern void cher_( char *uplo, const int *N, const float *alpha, complex *X, const int *incX,
// 					complex *AP, const int *lda);

// extern void chpr_( char *uplo, const int *N, const float *alpha, complex *X, const int *incX,
// 					complex *AP);

// extern void stbmv_( char *uplo, char *trans, char *diag, const int *N, const int *K, 
// 					float *A, const int *lda, float *X, const int *incX);

int main() {

	int n = 3;
	int one = 1;
	
	char uplo = 'L';

	float alpha = 1.0;	
	float beta = 1.0;

	float AP[6] = {8.0, 4.0, 2.0, 6.0, 7.0, 3.0};
	// | 8.0  4.0  2.0 |
	// | 4.0  6.0  7.0 |
	// | 2.0  7.0  3.0 |

	float X[3] = {3, 2, 1};
	float Y[3] = {5, 3, 2};
	
	// correct
	sspmv_(&uplo, &n, &alpha, &AP[0], &X[0], &one, &beta, &Y[0], &one);
	PRINT_s(Y, 3);


// 	int lda = 3;

// 	// for lower storage mode, keep positions while the values are not used
// 	float AP2[3*3] = {8.0, 4.0, 2.0, 0, 6, 7, 0, 0, 3};
// 	float X2[3] = {3, 2, 1};

// 	// correct
// 	ssyr_(&uplo, &n, &alpha, &X2[0], &one, &AP2[0], &lda);
// 	PRINT_s(AP2, 9);




// 	float AP3[6] = {8.0, 4.0, 2.0, 6.0, 7.0, 3.0};
// 	float X3[3] = {3, 2, 1};

// 	// correct
// 	sspr_(&uplo, &n, &alpha, &X3[0], &one, &AP3[0]);
// 	PRINT_s(AP3, 6);




// 	// for lower storage mode, keep positions while the values are not used
// 	complex AX4[9] = {{1, }, {3, -5}, {2, 3}, {0, 0}, {7, }, {4, 8}, {0, 0}, {0, 0}, {6, }};
// 	complex X4[3] = {{1.0, 2.0}, {4.0, 0.0}, {3.0, 4.0}};

// 	// correct
// 	cher_(&uplo, &n, &alpha, &X4[0], &one, &AX4[0], &lda);
// 	PRINT_c(AX4, 9);



// 	complex AX5[6] = {{1, }, {3, -5}, {2, 3}, {7, }, {4, 8}, {6, }};
// 	complex X5[3] = {{1.0, 2.0}, {4.0, 0.0}, {3.0, 4.0}};
	
// 	// correct
// 	chpr_(&uplo, &n, &alpha, &X5[0], &one, &AX5[0]);
// 	PRINT_c(AX5, 6);



//  	uplo = 'L';
// 	char trans = 'N';
// 	char diag = 'N';
// 	int K = 2;	// upper/lower band width of matrix A
// 	float AX6[9] = {8, 4, 2, 6, 7, 0, 3};
// 	float X6[3] = {3, 2, 1};
	
// 	stbmv_(&uplo, &trans, &diag, &n,  &K, &AX6[0], &lda, &X6[0], &one);
// 	PRINT_s(X6, 3);


// 	// https://www.ibm.com/support/knowledgecenter/SSFHY8_6.2/reference/am5gr_hstbmv.html
//  	uplo = 'L';
// 	trans = 'T';
// 	diag = 'N';
// 	n = 7;
// 	K = 3;	// upper/lower band width of matrix A
// 	lda = 5;
// 	// stored in AX with ku + kl + 2
// 	float AX7[35] = {1, 1, 1, 1, 0,
// 					2, 2, 2, 2, 0, 
// 					3, 3, 3, 3, 0, 
// 					4, 4, 4, 4, 0,
// 					5, 5, 5, 0, 0,
// 					6, 6, 0, 0, 0,
// 					7, 0, 0, 0, 0};
// /*
// 	float AX71[28] = {1, 1, 1, 1,
// 					2, 2, 2, 2, 
// 					3, 3, 3, 3, 
// 					4, 4, 4, 4,
// 					5, 5, 5, 0,
// 					6, 6, 0, 0,
// 					7, 0, 0, 0};
//  */
// 	float X7[7] = {1,2,3,4,5,6,7};
	
// 	stbmv_(&uplo, &trans, &diag, &n,  &K, &AX7[0], &lda, &X7[0], &one);
// 	PRINT_s(X7, 7);



	return 0;
}
