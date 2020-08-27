#include <stdio.h>
#include <string.h>

extern double dasum_(const int *N, double *DX, const int *incX);

void printd(const int n, double *X);

int main() {
	int one = 1;
	int N = 5;
	
	double DX[5] = {2, 4, 2, 5, 7}; // holds 1,2,3,4,5
	printd(5, DX);

	double asum = dasum_(&N, DX, &one);
	
	printd(N, DX);
	printd(1, &asum);

	return 0;
}

void printd(const int n, double *X)
{
	int i;
	printf(" === Vector A (double): \n");
	for (i = 0; i < n; ++i)
		printf("%f\n", X[i]);
}

