/* Calling CGEQRF and CUNGQR to compute Q without workspace querying */

#include "myutils.h"
#include <lapacke.h>
#include <cblas.h>
#include <math.h>

int main(int argc, const char *argv[])
{
   lapack_complex_float    *a,*tau;

   lapack_complex_float    one,zero;
   one = lapack_make_complex_float(1.0,0.0);
   zero = lapack_make_complex_float(0.0,0.0);

   lapack_int  info,m,n,lda;
   float err = 0.0;
   m = 3;   n = 2;   lda = m;

   a = calloc(m*m, sizeof(lapack_complex_float));
   tau = calloc(m, sizeof(lapack_complex_float));

   int i,j;
   for(j=0; j<n; j++)
      for(i=0; i<m; i++)
         a[i+j*m] = lapack_make_complex_float(i+1, j+1);

   complex *ap = a;
   printm(m, n, ap);

   // QR factorization
   info = LAPACKE_cgeqrf(LAPACK_COL_MAJOR, m, n, a, lda, tau);
   printm(m, n, ap);

   // QR factorization, generates Q after qrf
   info = LAPACKE_cungqr(LAPACK_COL_MAJOR, m, m, n, a, lda, tau);
   printm(m, m, ap);

   // validate that Q (a) is unitary matrix

   lapack_complex_float  *r;
   r = calloc(n*n, sizeof(lapack_complex_float));

   for(j=0;j<n;j++)
      for(i=0;i<n;i++)
         r[i+j*n] = (i==j) ? -one: zero;
    complex *rp = r;
     printv(n, rp);

   cblas_cgemm(CblasColMajor, CblasConjTrans, CblasNoTrans,
               n, n, m, &one, a, lda, a, lda, &one, r, n);
   
   printf("GEMM: test whether Q is a unitary matrix.\n");
   printm(m, m, ap);
   printv(n, rp);

   for(i=0;i<n;i++)
      for(j=0;j<n;j++)
         err = fmax( err, cabs(r[i+j*n]) );
   printf("error = %e \n", err);

   free(tau);
   free(r);
   free(a);
   return(info);
}

