#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {float real,imag;} complex;
typedef struct {double real,imag;} complex16;

extern void dgemm_(const char *transa, const char *transb, const int *m, const int *n, const int *k, 
                  const double *alpha, 
                  const double *a, const int *lda, const double *b, const int *ldb, const double *beta, 
                  const double *c, const int *ldc);

void init(double *matrix, int row, int column) {
  for (int j = 0; j < column; j++) {
    for (int i = 0; i < row; i++) {
      matrix[j * row + i] = ((double)rand()) / RAND_MAX;
    }
  }
}

// Print a vector with its name and location

void print(const char *name, const double *matrix, int row, int column) {
  printf("Matrix %s has %d rows and %d columns:\n", name, row, column);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      printf("  %.3f ", matrix[j * row + i]);
    }
    printf("\n");
  }
  printf("\n");
}



int main(int argc, char *argv[]) {

	const int rowsA = 2;
	const int colsB = 4;
	const int common = 6;

	int i, j, k = 0;

	double A[rowsA * common];
	double B[common * colsB];
	double C[rowsA * colsB];
	double D[rowsA * colsB];

	char transA = 'N', transB = 'N';
	double one = 1.0, zero = 0.0;

	srand(time(NULL));

	init(A, rowsA, common);
	init(B, common, colsB);

	dgemm_(&transA, &transB, &rowsA, &colsB, &common, &one, A, &rowsA, B, &common, &zero, C, &rowsA);

	for (i = 0; i < colsB; i++) {
		for (j = 0; j < rowsA; j++) {
			D[i * rowsA + j] = 0;
			for (k = 0; k < common; k++) {
				D[i * rowsA + j] += A[k * rowsA + j] * B[k + common * i];
			}
		}
	}

	print("A", A, rowsA, common);
	print("B", B, common, colsB);
	print("C", C, rowsA, colsB);
	print("D", D, rowsA, colsB);

	return 0;
}
