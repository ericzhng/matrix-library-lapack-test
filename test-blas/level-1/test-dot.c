
#include <stdio.h>
#include <stdlib.h>

typedef struct {float real,imag;} complex;
typedef struct {double real,imag;} complex16;

// FORTRAN adds _ after all the function names
// and all variables are called by reference

extern float sdot_(const int *N, const float *a, const int *inca, 
			const float *b, const int *incb);

extern double ddot_(const int *N, const double *a, const int *inca, 
			const double *b, const int *incb);

extern double dsdot_(const int *N, const float *a, const int *inca, 
			const float *b, const int *incb);

extern float sdsdot_(const int *N, const float *alpha, const float *a, const int *inca, 
			const float *b, const int *incb);


extern complex cdotu_(const int *N, const complex *a, const int *inca, 
			const complex *b, const int *incb);

extern complex16 zdotu_(const int *N, const complex16 *a, const int *inca, 
			const complex16 *b, const int *incb);


extern complex cdotc_(const int *N, const complex *a, const int *inca, 
			const complex *b, const int *incb);

extern complex16 zdotc_(const int *N, const complex16 *a, const int *inca, 
			const complex16 *b, const int *incb);



/* double ddot(int N, double *a, int inca, double *b, int incb) {
	return ddot_(&N, a, &inca, b, &incb);
} */

int main(int argc, char **argv) {

	int n = 3;
	int one = 1;


	float sA[3] = {1.0, 2.0, 3.0};
	float sB[3] = {4.0, 5.0, 6.0};

	float sResult1 = sdot_(&n, sA, &one, sB, &one);
	double sResult2 = dsdot_(&n, sA, &one, sB, &one);
	printf("sResult is: %f \n", sResult1);
	printf("sResult is: %lf \n", sResult2);

	float alpha = 2.0;
	float sResult3 = sdsdot_(&n, &alpha, sA, &one, sB, &one);
	printf("sResult is: %f \n", sResult3);



	// you can define the arrays in one of two ways
	// on the heap
	double *dA = (double *)malloc(3 * sizeof(double));
	dA[0] = 1.0;
	dA[1] = 2.0;
	dA[2] = 3.0;

	// on the stack
	double dB[3] = {4.0, 5.0, 6.0};

	double dResult = ddot_(&n, dA, &one, dB, &one);
	printf("dResult is: %lf \n", dResult);



	complex cA[3];
	complex cB[3];
	
	cA[0].real = 1.0; cA[0].imag = 2.0;
	cA[1].real = 2.0; cA[1].imag = 3.0;
	cA[2].real = 3.0; cA[2].imag = 4.0;

	cB[0].real = 1.0; cB[0].imag = 2.0;
	cB[1].real = 2.0; cB[1].imag = 3.0;
	cB[2].real = 3.0; cB[2].imag = 4.0;

	complex cResult1 = cdotu_(&n, cA, &one, cB, &one);
	complex cResult2 = cdotc_(&n, cA, &one, cB, &one);
	printf("cResult is: %f + 1j * %f \n", cResult1.real, cResult1.imag);
	printf("cResult is: %f + 1j * %f \n", cResult2.real, cResult2.imag);



	complex16 zX[3];
	complex16 zY[3];

	zX[0].real = 1.0; zX[0].imag = 0.0;
	zX[1].real = 0.0; zX[1].imag = 2.0;
	zX[2].real = 3.0; zX[2].imag = 0.0;
	
	zY[0].real = 1.0; zY[0].imag = 0.0;
	zY[1].real = 0.0; zY[1].imag = 2.0;
	zY[2].real = 3.0; zY[2].imag = 0.0;
	
	complex16 zResult = zdotu_(&n, zX, &one, zY, &one);
	complex16 zResult2 = zdotc_(&n, zX, &one, zY, &one);
	printf("zResult is: %f + 1j * %f \n", zResult.real, zResult.imag);
	printf("zResult is: %f + 1j * %f \n", zResult2.real, zResult2.imag);




	return 0;
};
