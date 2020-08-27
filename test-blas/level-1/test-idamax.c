#include <stdio.h>
#include <string.h>

extern int idamax_(const int *N, double *DX, const int *incX);

void printd(const int n, double *X);

int main() {
	int one = 1;
	int N = 5;
	
	double DX[5] = {2, 4, 2, 5, 7.0, 7.0}; // holds 1,2,3,4,5
	printd(5, DX);

	int pos = idamax_(&N, DX, &one);
	
	printd(N, DX);
	printf("max pos = %d\n", pos);

	return 0;
}

void printd(const int n, double *X)
{
	int i;
	printf(" === Vector A (double): \n");
	for (i = 0; i < n; ++i)
		printf("%f\n", X[i]);
}

