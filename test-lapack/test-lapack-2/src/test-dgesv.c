#include "blaio.h" /* Basic Linear Algebra I/O */
#include "myutils.h"


void dgesv_(const int *N, const int *nrhs, 
            double *A, const int *lda,
            int *ipiv,
            double *b, const int *ldb, 
            int *info);


int main(int argc, char **argv) {

  double a[4 * 4] = {1, 2, 3, 4,
                            6, 7, 9, 9,
                            11, 12, 19, 14,
                            16, 17, 18, 12};

  double b[4] = {1, 3, 5, 6};

  int pivs[4], inf = 0;
  int n = 4, lda = 4, nrhs = 1, ldb = 4;
  char tbuf[1024];
  int i;


  sprintf(tbuf, " a[%dx%d]= ", 4, 4);
  printMatrix(CblasColMajor, 4, 4, a, 15, 10, NULL, NULL, NULL, NULL, NULL, tbuf);

  sprintf(tbuf, " b[%dx%d]= ", 1, 4);
  printMatrix(CblasColMajor, 1, 4, b, 15, 10, NULL, NULL, NULL, NULL, NULL, tbuf);

  dgesv_(&n, &nrhs, a, &lda, pivs, b, &ldb, &inf);

  if (inf == 0) {
    printf("Successful Solution\n");
  } else if (inf < 0) {
    printf("Illegal value at: %d\n", -(int)inf);
    exit(1);
  } else if (inf > 0) {
    printf("Matrix was singular\n");
    exit(1);
  } else {
    printf("Unknown Result (Can't happen!)\n");
    exit(1);
  }


  sprintf(tbuf, "a'[%dx%d]= ", 4, 4);
  printMatrix(CblasColMajor, 4, 4, a, 15, 10, NULL, NULL, NULL, NULL, NULL, tbuf);

  sprintf(tbuf, "b'[%dx%d]= ", 1, 4);
  printMatrix(CblasColMajor, 1, 4, b, 15, 10, NULL, NULL, NULL, NULL, NULL, tbuf);


  printf("PIV = ");
  for (i = 0; i < 4; i++)
    printf("%4d ", (int)(pivs[i]));
  printf("\n");

  return 0;

}

