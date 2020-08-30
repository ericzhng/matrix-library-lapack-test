/* Calling DGELS using row-major order */

#include "myutils.h"
#include <lapacke.h>
#include "lapacke_example_aux.h"

int main(int argc, const char *argv[])
{
   int info, m, n, lda, ldb, nrhs;

   m = 6;
   n = 4;
   nrhs = 2;

   double a[6*4] = {
      1.44, -7.84, -4.39,  4.53,
      -9.96, -0.28, -3.24,  3.83,
      -7.55, 3.24, 6.27, -6.64,
      8.34, 8.09, 5.28,  2.06,
      7.08, 2.52, 0.74, -2.47,
      -5.45, -5.70, -1.19,  4.70
   };
   double b[6*2] = {
      8.58, 9.35,
      8.26, -4.43,
      8.48, -0.70,
      -5.28, -0.26,
      5.72, -7.36,
      8.93, -2.52
   };

   lda = n;
   ldb = nrhs;

   print_matrix_rowmajor( "Initial", m, n, a, lda );
   print_matrix_rowmajor( "Initial", m, nrhs, b, ldb );

   info = LAPACKE_dgels(LAPACK_ROW_MAJOR, 'N' , m, n, nrhs, a, lda, b, ldb);

   print_matrix_rowmajor( "Solution", m, n, a, lda );
   print_matrix_rowmajor( "Solution", n, nrhs, b, ldb );

   return(info);
}
