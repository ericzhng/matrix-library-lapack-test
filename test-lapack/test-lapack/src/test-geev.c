// finding the eigenvalues of a complex16 matrix

#include <stdio.h>
#include "myutils.h"

/* dimension of matrix */
#define size 3

/* ZGEEV prototype */
extern void zgeev_(char *jobvl, char *jobvr, int *n,
                   complex16 *A, int *lda,
                   complex16 *w,
                   complex16 *vl, int *ldvl,
                   complex16 *vr, int *ldvr,
                   complex16 *work, int *lwork,
                   double *rwork,
                   int *info);

// jobvl: 'N' or 'V'
// w: contains the computed eigenvalues
// wr, wi: contains the real/imaginary parts of eigenvalues
// vl, vr: left/right eigenvectors
// work: complex array work returns optimal lwork
// lwork: input integer, the dimension of the array work, bigger than 2*N
// rwork: real array
// info: 0 sucess, <0: ith argument had an illegal value, >0, the QR algorithm failed, and no output

int main()
{
  int N = 3;
  int ok, lda, ldvl, ldvr, lwork;

  complex16 w[3], vl[9], vr[9], work[6];
  double rwork[6];

  // initial row-major storage
  complex16 A[3 * 3] = {{3.1, -1.8}, {1.3, 0.2}, {-5.7, -4.3}, 
					  {1.0, 0}, {-6.9, 3.2}, {5.8, 2.2}, 
					  {3.4, -4}, {7.2, 2.9}, {-8.8, 3.2}};

  // in order for Fortran column-major storage
  mtx_transpose(&A[0], 3, 3);

  printm(3, 3, A);
  
  char jobvl = 'V';
  lda = 3;
  ldvl = 3;         /* to the routine in variables */
  ldvr = 3;         /* to the routine in variables */
  lwork = 3 * size; /* we want to pass */

  /* find solution using LAPACK routine ZGEEV, all the arguments have to */
  /* be pointers and you have to add an underscore to the routine name */
  zgeev_(&jobvl, &jobvl, &N, A, &lda, w, vl, &ldvl, vr, &ldvr, work, &lwork, rwork, &ok);

  printm(3, 3, vl);
  printm(3, 3, vr);
  printv(6, work);
  printv(6, rwork);

  /* parameters in the order as they appear in the function call
      no left eigenvectors, no right eigenvectors, order of input matrix A,
      input matrix A, leading dimension of A, array for eigenvalues,
      array for left eigenvalue, leading dimension of DUMMY,
      array for right eigenvalues, leading dimension of DUMMY,
      workspace array dim>=2*order of A, dimension of WORK
      workspace array dim=2*order of A, return value */

  if (ok == 0) /* output of eigenvalues */
    printv(3, w);
  else
    printf("An error occured!\n");

  return 0;
}
