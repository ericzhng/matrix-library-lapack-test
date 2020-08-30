
// utils has to come first since it defines the complex data types

#include "myutils.h"
#include <lapacke.h>
#include "lapacke_example_aux.h"

int main() {

  double a[] = {1, 2, 3, 4};     // NO need for column-major mode
  double b[] = {19, 22, 43, 50}; // NO need for column-major mode

  int n = 2;
  int nrhs = 2;
  int lda = n;
  int ipiv[n];
  int ldb = n;

  print_matrix_rowmajor( "A", n, n, a, lda );
  print_matrix_rowmajor( "b", n, ldb, b, ldb );

  int info = LAPACKE_dgesv(LAPACK_ROW_MAJOR, n, nrhs, a, lda, ipiv, b, ldb);

  print_matrix_rowmajor( "A", n, n, a, lda );
  print_matrix_rowmajor( "b", n, ldb, b, ldb );

  printf("info = %d\n", info);


  double M[4] = {
      2, 1.5388, 
      1.5388,  2,
  };

  double V[2] = {
      1.5593,
      1.6987,
  };
  
  info = LAPACKE_dgesv(LAPACK_ROW_MAJOR, 2, 1, M, lda, ipiv, V, 1);

  print_matrix_rowmajor( "b", n, 1, V, 1 );
  printf("info = %d\n", info);

  return 0;
}
