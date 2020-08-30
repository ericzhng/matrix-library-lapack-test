#include "myutils.h"

/* Purpose:

DSYEV computes the eigenvalues and, optionally, the left and/or right
eigenvectors for SY matrices

     DSYEV computes all eigenvalues and, optionally, eigenvectors of a
     real symmetric matrix A.

Parameters:
    [in]	JOBZ
              JOBZ is CHARACTER*1
              = 'N':  Compute eigenvalues only;
              = 'V':  Compute eigenvalues and eigenvectors.

    [in]	UPLO
              UPLO is CHARACTER*1
              = 'U':  Upper triangle of A is stored;
              = 'L':  Lower triangle of A is stored.

    [in]	N
              N is INTEGER
              The order of the matrix A.  N >= 0.

    [in,out]	A
              A is DOUBLE PRECISION array, dimension (LDA, N)
              On entry, the symmetric matrix A.  If UPLO = 'U', the
              leading N-by-N upper triangular part of A contains the
              upper triangular part of the matrix A.  If UPLO = 'L',
              the leading N-by-N lower triangular part of A contains
              the lower triangular part of the matrix A.
              On exit, if JOBZ = 'V', then if INFO = 0, A contains the
              orthonormal eigenvectors of the matrix A.
              If JOBZ = 'N', then on exit the lower triangle (if UPLO='L')
              or the upper triangle (if UPLO='U') of A, including the
              diagonal, is destroyed.

    [in]	LDA
              LDA is INTEGER
              The leading dimension of the array A.  LDA >= max(1,N).

    [out]	W
              W is DOUBLE PRECISION array, dimension (N)
              If INFO = 0, the eigenvalues in ascending order.

    [out]	WORK
              WORK is DOUBLE PRECISION array, dimension (MAX(1,LWORK))
              On exit, if INFO = 0, WORK(1) returns the optimal LWORK.

    [in]	LWORK
              LWORK is INTEGER
              The length of the array WORK.  LWORK >= max(1,3*N-1).
              For optimal efficiency, LWORK >= (NB+2)*N,
              where NB is the blocksize for DSYTRD returned by ILAENV.

              If LWORK = -1, then a workspace query is assumed; the routine
              only calculates the optimal size of the WORK array, returns
              this value as the first entry of the WORK array, and no error
              message related to LWORK is issued by XERBLA.

    [out]	INFO
              INFO is INTEGER
              = 0:  successful exit
              < 0:  if INFO = -i, the i-th argument had an illegal value
              > 0:  if INFO = i, the algorithm failed to converge; i
                    off-diagonal elements of an intermediate tridiagonal
                    form did not converge to zero.

*/

void dsyev_(char *jobz, char *uplo, int *n, double *a, int *lda, double *w,
            double *work, int *lwork, int *info);

int main()
{
  char jobz = 'V';
  char uplo = 'U';

  int n = 5;
  int lda = n;

  // initialize a
  double *a;
  a = (double *)malloc(sizeof(double) * lda * n);
  set_random(a, lda, n);
 	mtx_transpose(a, n, n);
  printm(n, n, a);

  double *w;
  w = (double *) malloc(sizeof(double) * n);

  double *work;

  int lwork = -1;;
  double wwork;

  double t1, t2;

  int info;

  // get workspace information
  dsyev_(&jobz, &uplo, &n, a, &lda, w, &wwork, &lwork, &info);

  lwork = wwork + 1;

  work = (double *) malloc(sizeof(double) * lwork);

  t1 = cputime();

  // do the real work:
  dsyev_(&jobz, &uplo, &n, a, &lda, w, work, &lwork, &info);

  t2 = cputime() - t1;

  printv(n, w);
  
  printf(" n = %d: info = %d, time = %lf\n", n, info, t2);

  free(work);
  free(a);
  free(w);
  
  return 0;
}

