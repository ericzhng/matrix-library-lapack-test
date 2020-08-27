#include <stdio.h>
#include <string.h>

extern double dnrm2_(const int *N, double *DX, const int *incX);

void printd(const int n, double *X);

int main() {
	int one = 1;
	int N = 6;
	// one way to initialize
	double DX[6] = {[0] = 3, [2 ... 5] = 5};
	printd(6, DX);
	
	double nrm2 = dnrm2_(&N, DX, &one);
	
	printd(1, &nrm2);
	
	return 0;
}

void printd(const int n, double *X)
{
	int i;
	printf(" === Vector A (double): \n");
	for (i = 0; i < n; ++i)
		printf("%f\n", X[i]);
}

