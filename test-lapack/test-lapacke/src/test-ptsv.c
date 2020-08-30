
#include "myutils.h"
#include <lapacke.h>

int main() {
  int N = 4;
  int nrhs = 2;
  int ldb = 4;

  // positive symmetric definite matrix
  // | 1.0  1.0  0.0  0.0 |                                   
  // | 1.0  2.0  1.0  0.0 |                                   
  // | 0.0  1.0  4.2  1.0 |                                   
  // | 0.0  0.0  1.0  1.0 |    

  double diagonal[4] = {1, 2, 4.2, 1};
  double subdiagonal[3] = {1, 1, 1};

  //     | 2.0 -2.0 |                                           
  // B = | 4.0 -3.0 |                                           
  //     | 5.0  0.0 |                                           
  //     | 2.0  1.0 |            

  double solution[4*2] = {2, 4, 5, 2, -2, -3, 0, 1};

  LAPACKE_dptsv(LAPACK_COL_MAJOR, N /*size of matrix*/,
                nrhs /*number of columns in solution*/, diagonal, subdiagonal,
                solution, ldb /*leading dimension of solution vector*/);

  printm(N, nrhs, solution);
}
