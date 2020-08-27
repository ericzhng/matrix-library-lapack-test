/* Calling CGEQRF and CUNGQR to compute Q without workspace querying */

#include "myutils.h"
#include <lapacke.h>
#include <cblas.h>

#define n1 5

int main(int argc, const char *argv[])
{
   int     info,m,n,lda;

   m = 5;   n = 3;   lda = m;

   double a[5*5] = { [0] = 1, 1, 1, 
                     [1*n1] = 2, 2, 2, 
                     [2*n1] = 3, 3, 3, 
                     [3*n1] = 4, 4, 4, 
                     [4*n1] = 5, 5, 5};
   
   double tau[5] = {0.0};

   printm2(m, n1, a, "row");

   // QR factorization
   info = LAPACKE_dgeqrf(LAPACK_ROW_MAJOR, m, n, a, lda, tau);
   printm2(m, n1, a, "row");

   printv(m, tau);
   
   // QR factorization, generates Q after qrf
   info = LAPACKE_dorgqr(LAPACK_ROW_MAJOR, m, n, n, a, lda, tau);
   printm2(m, n1, a, "row");

   return(info);
}

