#include <stdio.h>
#include <string.h>

extern void dcopy_(const int *N, double *DX, const int *incX, 
				 double *DY, const int *incY);

void printd(const int n, double *X);

int main() {
	int one = 1;
	
	// one way to initialize
	double array[6] = {[0 ... 5] = 5};
	printd(6, array);
	
	double n1[5] = {[4]=5,[0]=1,2,3,4}; // holds 1,2,3,4,5
	printd(5, n1);

	const int N = 4;
	double DX[] = {2.4, 4.0, 1, 2};
	
	// another way
	double DY[N];
	memset( DY, 0, N*sizeof(double) );
	
	printd(N, DX);
	printd(N, DY);
	
	dcopy_(&N, DX, &one, DY, &one);
	
	printd(N, DY);

	return 0;
}

void printd(const int n, double *X)
{
	int i;
	printf(" === Vector A (double): \n");
	for (i = 0; i < n; ++i)
		printf("%f\n", X[i]);
}

