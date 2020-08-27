#include <stdio.h>

typedef struct {float real,imag;} complex;
typedef struct {double real,imag;} complex16;

extern void saxpy_(const int *N, const float *a, float *X,
                   const int *incX, float *Y, const int *incY);

extern void daxpy_(const int *N, const double *a, double *X,
                   const int *incX, double *Y, const int *incY);

extern void caxpy_(const int *N, const complex *a, complex *X,
                   const int *incX, complex *Y, const int *incY);

extern void zaxpy_(const int *N, const complex16 *a, complex16 *X,
                   const int *incX, complex16 *Y, const int *incY);

void prints(const int n, float *X);
void printd(const int n, double *X);
void printc(const int n, complex *X);
void printz(const int n, complex16 *X);

int main() {

	int n = 3;
	int one = 1;


	float sAlpha = 2.0;
	float sX[3] = {1, 2, 3};
	float sY[3] = {3, 4, 5};
	
	prints(n, sX);
	prints(n, sY);
	saxpy_(&n, &sAlpha, &sX[0], &one, &sY[0], &one);
	prints(n, sY);



	double dAlpha = 4.0;
	double dX[3] = {1, 2, 3};
	double dY[3] = {3, 4, 5};

	printd(n, dX);
	printd(n, dY);
	daxpy_(&n, &dAlpha, &dX[0], &one, &dY[0], &one);
	printd(n, dY);



	complex cAlpha = {0.0, 1.0};
	complex cX[3];
	complex cY[3];
	
	cX[0].real = 1.0; cX[0].imag = 2.0;
	cX[1].real = 2.0; cX[1].imag = 3.0;
	cX[2].real = 3.0; cX[2].imag = 4.0;

	cY[0].real = 1.0; cY[0].imag = 2.0;
	cY[1].real = 2.0; cY[1].imag = 3.0;
	cY[2].real = 3.0; cY[2].imag = 4.0;

	printc(n, cX);
	printc(n, cY);
	caxpy_(&n, &cAlpha, &cX[0], &one, &cY[0], &one);
	printc(n, cY);




	complex16 zAlpha = {1.0, 1.0};
	complex16 zX[3];
	complex16 zY[3];

	zX[0].real = 1.0; zX[0].imag = 0.0;
	zX[1].real = 0.0; zX[1].imag = 2.0;
	zX[2].real = 3.0; zX[2].imag = 0.0;
	
	zY[0].real = 1.0; zY[0].imag = 0.0;
	zY[1].real = 0.0; zY[1].imag = 2.0;
	zY[2].real = 3.0; zY[2].imag = 0.0;
	
	printz(n, zX);
	printz(n, zY);
	zaxpy_(&n, &zAlpha, &zX[0], &one, &zY[0], &one);
	printz(n, zY);


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
