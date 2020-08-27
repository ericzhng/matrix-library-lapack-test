#include "myutils.h"

void dgesv_(const int *N, const int *nrhs, 
            double *A, const int *lda,
            int *ipiv,
            double *b, const int *ldb, 
            int *info);


void dgeqrf_(const int *M, const int *N,
            double *A, const int *lda,
            double *tau,
            double *work, const int *lwork,
            int *info);


void dgels_(const char *trans, 
            const int *M, const int *N, const int *nrhs,
            double *A, const int *lda, 
            double *b, const int *ldb,
            double *work, const int *lwork,
            int *info);



// used together, first one will change 
void dgesvd_(const char *jobu, const char *jobvt, 
            const int *M, const int *N,
            double *A, const int *lda, 
            double *S, 
            double *U, const int *ldu,
            double *VT, const int *ldvt,
            double *work, const int *lwork,
            int *info);

void dgelss_(const int *M, const int *N, const int *nrhs,
            double *A, const int *lda, 
            double *b, const int *ldb,
            double *S, double *rcond,
            int *rank,
            double *work, const int *lwork,
            int *info);



int main(void) {

  int info = 0;
  int lwork = 0;
  double work[30] = {0.0};

  /* 3x3 matrix A
   * 76 25 11
   * 27 40 51
   * 18 60 32
   */

  int N = 3;
  double A[9] = {76, 25, 11,
                27, 40, 51,
                18, 60, 32};
  int lda = N;

  // double A[9] = {1, 0, 0,
  //               0, 2, 0,
  //               0, 0, 3};

  // in order for Fortran column-major storage
 	mtx_transpose(A, N, N);
	printm(N, N, A);



// solve linear systems

  fprintf(stderr, "\n=====================");
  fprintf(stderr, "\nTest with dgesv (LU)\n");
  fprintf(stderr, "=====================\n");

  double b1[3] = {10, 7, 43};
  double A1[9] = {0.0};
  mtx_copy(A, A1, N, N);

  int nrhs = 1;
  int ipiv[3] = {0.0};
  int ldb = N;

	printm(N, N, A1);
  dgesv_(&N, &nrhs, A1, &lda, ipiv, b1, &ldb, &info);
	printm(N, N, A1);
	printv(N, ipiv);

  if (info == 0) /* succeed */
	  printv(N, b1);
  else
    fprintf(stderr, "dgesv_ fails with error_code %d\n", info);



// linear least squre 

  fprintf(stderr, "\n=====================");
  fprintf(stderr, "\nTest with dgels (QR)\n");
  fprintf(stderr, "=====================\n");

  double b2[3] = {10, 7, 43};

  double A2[9] = {0.0};
  mtx_copy(A, A2, N, N);

  lwork = 1*N;
  double tau[3] = {0.0};
  
	printm(N, N, A2);
  dgeqrf_(&N, &N, A2, &lda, tau, work, &lwork, &info);
	printm(N, N, A2);
	printv(N, tau);

  if (info == 0) /* succeed */
	  fprintf(stderr, "dgeqrf_ succeed\n");
  else
    fprintf(stderr, "dgeqrf_ fails with error_code %d\n", info);

  char trans = 'N';
  lwork = 3*N;

  double A21[9] = {0.0};
  mtx_copy(A, A21, N, N);

  dgels_(&trans, &N, &N, &nrhs, A21, &lda, b2, &ldb, work, &lwork, &info);
	printm(N, N, A21);

  if (info == 0) /* succeed */
	  printv(N, b2);
  else
    fprintf(stderr, "dgels_ fails with error_code %d\n", info);






// linear least squre

  fprintf(stderr, "\n=====================");
  fprintf(stderr, "\nTest with dgelss (SVD)\n");
  fprintf(stderr, "=====================\n");

  double b3[3] = {10, 7, 43};
  double A3[9] = {0.0};
  mtx_copy(A, A3, N, N);

  char jobu = 'A';
  char jobvt = 'A';
  double S[3];

  double U[9];
  int ldu = N;
  double VT[9];
  int ldvt = N;

  int lwork2 = 25*N;
  double work2[25*3] = {0.0};

	printm(N, N, A3);
  dgesvd_(&jobu, &jobvt, &N, &N, A3, &lda, S, U, &ldu, VT, &ldvt, work2, &lwork2, &info);
	printm(N, N, A3);

	printm(N, N, U);
	printm(N, N, VT);

  if (info == 0) /* succeed */
	  printv(N, S);
  else
    fprintf(stderr, "dgesv_ fails with error_code %d\n", info);

  int rank = 0;
  double rcond = -0.1;
  lwork = 5*N;

  double A31[9] = {0.0};
  mtx_copy(A, A31, N, N);

  dgelss_(&N, &N, &nrhs, A31, &lda, b3, &ldb, 
          S, &rcond, &rank, 
          work, &lwork, &info);
  printm(N, N, A31);
  
  printv(1, &rank);

  if (info == 0) /* succeed */
  {
    printv(N, b3);
    printv(N, S);
  }
  else
    fprintf(stderr, "dgelss_ fails with error_code %d\n", info);


  return info;
}
