
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

double Arow[36] = { 4, 2, 0, 3, 1, 2,
                    3, 3, 3, 3, 2, 4,
                    0, 3, 2, 2, 3, 2,
                    4, 2, 2, 3, 4, 4,
                    0, 2, 0, 0, 0, 3,
                    3, 0, 3, 0, 2, 2};

double Brow[24] = { 2, 3, 2, 1,
                    2, 1, 4, 4, 
                    3, 3, 3, 2,
                    2, 2, 4, 4,
                    4, 1, 2, 0,
                    0, 0, 0, 4};

int main(void) {

  int n = 6;
  int nrhs = 4;
  int info;
  int lda, ldb, ipiv[n];

  lda = n;
  ldb = n;

  info = LAPACKE_dgesv(LAPACK_COL_MAJOR, n, nrhs, Acol, lda, ipiv, Bcol, ldb);
  printf("info = %d\n", info);
  
  printm2(n, n, Acol, "col");
  printm2(n, 4, Bcol, "c");
  printv(n, ipiv);

  ldb = 4;
  info = LAPACKE_dgesv(LAPACK_ROW_MAJOR, n, nrhs, Arow, lda, ipiv, Brow, ldb);
  printf("info = %d\n", info);
  
  printm2(n, n, Arow, "row");
  printm2(n, 4, Brow, "r");
  printv(n, ipiv);

  return 0;
}
