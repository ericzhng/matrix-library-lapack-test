#include "myutils.h"

extern void dgtsv_(const int *N, const int *NRHS, 
                  double *DL, double *D, double *DU,
                  double *B, const int *LDB,
                  int *info);

int main() {

  int N = 5;
  int nrhs = 1;

  double l[5] = {-1, -2, -1, -1};
  double d[5] = {2, 2, 3, 3, 1};
  double u[5] = {-1, -1, -1, -2};

  double b[5] = {1, 2, 3, 2, 1};

  int info = 0;
  int ldb = N;
  dgtsv_(&N, &nrhs, l, d, u, b, &ldb, &info);

  if (info != 0)
    fprintf(stderr, "failure with error %d\n", info);

  printv(N, b);

  return 0;
}
