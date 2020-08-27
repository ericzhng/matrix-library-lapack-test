/* Calling DGELS using row-major order */

#include <stdio.h>

#include <complex>
#define lapack_complex_float std::complex<float>
#define lapack_complex_double std::complex<double>
#include <lapacke.h>

extern "C" lapack_int LAPACKE_dgels(int matrix_layout, char trans, lapack_int m, lapack_int n, lapack_int nrhs, double* a, lapack_int lda, double* b, lapack_int ldb);

int main (int argc, const char * argv[])
{
   double a[5][3] = {1,1,1,2,3,4,3,5,2,4,2,5,5,4,3};
   double b[5][2] = {-10,-3,12,14,14,12,16,16,18,16};
   lapack_int info,m,n,lda,ldb,nrhs;
   int i,j;

   printf("hello world\n");

   m = 5;
   n = 3;
   nrhs = 2;
   lda = 3;
   ldb = 2;

   printf("before\n");

   info = LAPACKE_dgels(LAPACK_ROW_MAJOR, 'N', m, n, nrhs, *a, lda, *b, ldb);

   printf("after\n");

   for(i=0;i<n;i++)
   {
      for(j=0;j<nrhs;j++)
      {
         printf("%lf ",b[i][j]);
      }
      printf("\n");
   }
   
   printf("lapacke return flag: %d\n", info);
   getchar();
   return(info);
}
