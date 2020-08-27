/* Calling DGELS using row-major order */

#include "myutils.h"

#include <lapacke.h>

int main(int argc, const char *argv[])
{

   int info, m, n, lda, ldb, nrhs;

   m = 5;
   n = 3;
   nrhs = 2;
   lda = 3;
   ldb = 2;

   double a[5][3] = {1,1,1,2,3,4,3,5,2,4,2,5,5,4,3};
   double b[5][2] = {-10,-3,12,14,14,12,16,16,18,16};
   printm2(m, n, a[0], "r");
   printm2(m, nrhs, b[0], "r");

   info = LAPACKE_dgels(LAPACK_ROW_MAJOR, 'N' , m, n, nrhs, *a, lda, *b, ldb);
   printm2(m, n, a[0], "r");
   printm2(m, nrhs, b[0], "r");

   return(info);
}
