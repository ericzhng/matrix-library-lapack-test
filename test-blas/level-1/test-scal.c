#include <stdio.h>

typedef struct {float real,imag;} complex;
typedef struct {double real,imag;} complex16;

extern void sscal_(const int *N, const float *alpha, float *X,
                   const int *incX);
				   
extern void dscal_(const int *N, const double *alpha, double *X,
                   const int *incX);
				   
extern void cscal_(const int *N, const complex *alpha, complex *X,
                   const int *incX);
				   
extern void zscal_(const int *N, const complex16 *alpha, complex16 *X,
                   const int *incX);


extern void csscal_(const int *N, const float *alpha, complex *X,
                   const int *incX);
				   
extern void zdscal_(const int *N, const double *alpha, complex16 *X,
                   const int *incX);

void prints(const int n, float *X);
void printd(const int n, double *X);
void printc(const int n, complex *X);
void printz(const int n, complex16 *X);

int main() {

	int n = 3;
	int one = 1;

	// float
	float sAlpha = 2.0;
	float sA[3] = {1.3, 2.0, 3.4};
	
	prints(n, sA);
	sscal_(&n, &sAlpha, &sA[0], &one);
	prints(n, sA);


	// double
	double dAlpha = 4.0;
	double dA[3] = {1, 3, 2};
	
	printd(n, dA);
	dscal_(&n, &dAlpha, &dA[0], &one);
	printd(n, dA);



	// complex
	complex cAlpha = {0.0, 1.0};
	complex cA[3];
	cA[0].real = 1.0; cA[0].imag = 2.0;
	cA[1].real = 2.0; cA[1].imag = 3.0;
	cA[2].real = 3.0; cA[2].imag = 4.0;

	printc(n, cA);
	cscal_(&n, &cAlpha, &cA[0], &one);
	printc(n, cA);


	// complex16
	complex16 zAlpha = {1.0, 1.0};
	complex16 zA[3];
	zA[0].real = 1.0; zA[0].imag = 0.0;
	zA[1].real = 0.0; zA[1].imag = 2.0;
	zA[2].real = 3.0; zA[2].imag = 0.0;
	
	printz(n, zA);
	zscal_(&n, &zAlpha, &zA[0], &one);
	printz(n, zA);




	printc(n, cA);
	csscal_(&n, &sAlpha, &cA[0], &one);
	printc(n, cA);


	printz(n, zA);
	zdscal_(&n, &dAlpha, &zA[0], &one);
	printz(n, zA);


	return 0;
}


void prints(const int n, float *X)
{
	int i;
	printf(" === Vector A (float): \n");
	for (i = 0; i < n; ++i)
		printf("%f\n", X[i]);
}

void printd(const int n, double *X)
{
	int i;
	printf(" === Vector A (double): \n");
	for (i = 0; i < n; ++i)
		printf("%f\n", X[i]);
}

void printc(const int n, complex *X)
{
	int i;
	printf(" === Vector A (float complex): \n");
	for (i = 0; i < n; ++i)
		printf("%f + 1j * %f\n", X[i].real, X[i].imag);
}

void printz(const int n, complex16 *X)
{
	int i;
	printf(" === Vector A (double complex): \n");
	for (i = 0; i < n; ++i)
		printf("%f + 1j * %f\n", X[i].real, X[i].imag);
}
