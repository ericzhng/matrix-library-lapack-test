#include <stdio.h>

// // data type double only
// #include "blas.h"
// #include "myutils.h"

// declarations
extern void dswap_(const int *N, double *DX, const int *incX, 
				 double *DY, const int *incY);

void printd(const int n, double *X);

int main() {

	int one = 1;
	
	const int N = 4;
	double DX[] = {2.4, 4.0, 1, 2};
	double DY[] = {1.0, 2.0, 2, 4};
	
	printf("\nBefore executing: \n");
	printd(N, DX);
	printd(N, DY);

	// PRINT_d(DX, N);
	// PRINT_d(DY, N);

	dswap_(&N, DX, &one, DY, &one);

	printf("\nAfter executing: \n");
	printd(N, DX);
	printd(N, DY);

	return 0;
}

void printd(const int n, double *X)
{
	int i;
	printf(" === Vector (double): \n");
	for (i = 0; i < n; ++i)
		printf("%f\n", X[i]);
}
