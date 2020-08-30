
#include "myutils.h"
#include <lapacke.h>

double Acol[36] = {4, 3, 0, 4, 0, 3,
                2, 3, 3, 2, 2, 0,
                0, 3, 2, 2, 0, 3,
                3, 3, 2, 3, 0, 0,
                1, 2, 3, 4, 0, 2,
                2, 4, 2, 4, 3, 2};

double Bcol[24] = {2, 2, 3, 2, 4, 0,
                3, 1, 3, 2, 1, 0,
                2, 4, 3, 4, 2, 0, 
                1, 4, 2, 4, 0, 4};

int main(void) {

  int n = 6;
  int nrhs = 4;
  int info;
  int lda, ldb, ipiv[n];

  lda = n;
  ldb = n;

  info = LAPACKE_dgesv(LAPACK_COL_MAJOR, n, nrhs, Acol, lda, ipiv, Bcol, ldb);
  printf("info = %d\n", info);
  
  printm(n, n, Acol);
  printm(n, 4, Bcol);
  printv(n, ipiv);

  return 0;
}
