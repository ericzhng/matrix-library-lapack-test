Note:

1. This code was adapted to work for both CBLAS independent and LAPACK included CBLAS packages. There are some difference between them. 
For the one included in LAPACK:		CBLAS_ORDER order = CblasColMajor;
For the independent CBLAS package:	enum CBLAS_ORDER order = CblasColMajor;


2. test-dgemm-check was designed to test whether program is able to identify invalid parameters. It can accept two arguments:
	1st one: rout default: -1. choose between 1 and others. 1 is for cblas function, other is for Fortran blas function.
	2nd one: info default: 0. choose between 0-3, check different parameters.


