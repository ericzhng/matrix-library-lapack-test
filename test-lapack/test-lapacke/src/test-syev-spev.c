#include "myutils.h"
#include <lapacke.h>

int main()
{
  char jobz = 'V';
  char uplo = 'L';

  int n = 3;
  int lda = n;

  // A = [2, 2, 4;
  //     2, 3, 1;
  //     4, 1, 2];

  // initialize a
  double a[9] = {[0] = 2, 2, 4,
                [4] = 3, 1,
                [8] = 2};

  printm(n, n, a);

  // a = (double *)malloc(sizeof(double) * lda * n);
  // set_random(a, lda, n);

  double w[n];

  double t1, t2;

  int info, info2;

  t1 = cputime();
  info = LAPACKE_dsyev(LAPACK_COL_MAJOR, jobz, uplo, n, a, lda, w);
  t2 = cputime() - t1;

  printv(n, w);
  printm(n, n, a);
  printf(" n = %d: info = %d, time = %lf\n", n, info, t2);


  double z[9];
  int ldz = n;

  double ap[6] = {2, 2, 4, 3, 1, 2};

  t1 = cputime();
  info2 = LAPACKE_dspev(LAPACK_COL_MAJOR, jobz, uplo, n, ap, w, z, ldz);
  t2 = cputime() - t1;
  
  printv(n, w);
  printv(6, ap);
  printm(n, n, z);
  printf(" n = %d: info = %d, time = %lf\n", n, info2, t2);

  return 0;
}
