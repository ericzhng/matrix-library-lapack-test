/* Calling CGEQRF and CUNGQR to compute Q without workspace querying */

#include "myutils.h"
#include <cblas.h>
#include <lapacke.h>
#include "lapacke_example_aux.h"

#define n1 5

int main(int argc, const char *argv[])
{
   int     info,m,n,lda;

   m = 5;   n = 3;   lda = m;

   double a[5*5] = { [0] = 1, 1, 2, 
                     [1*n1] = 2, 1, 2, 
                     [2*n1] = 3, 2, 3, 
                     [3*n1] = 4, 1, 4, 
                     [4*n1] = 5, 2, 2};
   
   double tau[5] = {0.0};
   print_matrix_rowmajor( "A", m, n, &a[0], lda );

   // QR factorization
   info = LAPACKE_dgeqrf(LAPACK_ROW_MAJOR, m, n, a, lda, tau);
   print_matrix_rowmajor( "A", m, n, &a[0], lda );

   // QR factorization, generates Q after qrf
   info = LAPACKE_dorgqr(LAPACK_ROW_MAJOR, m, m, m, a, lda, tau);
   print_matrix_rowmajor( "A", m, m, &a[0], lda );

   return(info);
}
