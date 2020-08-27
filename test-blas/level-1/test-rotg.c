#include <stdio.h>

extern void drotg_(double *DA, double *DB, double *C,double *S);

extern void drot_(const int *N, const double *DX, const int *incX, 
			const double *DY, const int *incY, double *C,double *S);

extern void drotmg_(double *DD1, double *DD2, double *DX1,double *DY1, 
			double *PARAM);

extern void drotm_(const int *N, const double *DX, const int *incX, 
			const double *DY, const int *incY, double *PARAM);

void printd(const int n, double *X);

int main() {
	int one = 1;
	
/*	// conventional givens rotation

	double DA_t = 2.0;
	double DB_t = 3.0;
	
	double C_t = 0, S_t = 0;
	double *C = &C_t, *S = &S_t;
	
	drotg_(&DA_t, &DB_t, C, S);
	
	printf("DA = %f\n", DA_t);
	printf("DB = %f\n", DB_t);
	
	printf("C = %f\n", *C);
	printf("S = %f\n", *S);

	
	const int N = 4;
	double DX[] = {2.4, 4.0, 1, 2};
	double DY[] = {1.0, 2.0, 2, 4};
	
	drot_(&N, DX, &one, DY, &one, C, S);
	
	printd(N, DX);
	printd(N, DY);
*/
	
	// modified givens rotation
	
	double DD1_t = 2, DD2_t = 3, DX1_t = 2, DY1_t = 1;

	double *DD1 = &DD1_t;
	double *DD2 = &DD2_t;
	double *DX1 = &DX1_t;
	double *DY1 = &DY1_t;
	
	double PARAM[5] = {0.0};
	
	drotmg_(DD1, DD2, DX1, DY1, PARAM);
	
	printd(5, PARAM);
	
	const int N1 = 4;
	double DX4[] = {1.0, 1.0, 5, 2};
	double DY4[] = {2.0, 3.0, 2, 3};
	
	drotm_(&N1, DX4, &one, DY4, &one, PARAM);
	
	printd(N1, DX4);
	printd(N1, DY4);
	
	return 0;
}

void printd(const int n, double *X)
{
	int i;
	printf(" === Vector A (double): \n");
	for (i = 0; i < n; ++i)
		printf("%f\n", X[i]);
}

