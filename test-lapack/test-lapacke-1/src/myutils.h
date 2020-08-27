#ifndef MY_UTILS_H
#define MY_UTILS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/time.h>
#include <sys/times.h>

#include <assert.h>
#include <ctype.h>
#include <math.h>

typedef struct {float real,imag;} complex;
typedef struct {double real,imag;} complex16;

// initialize a matrix/vector with random double values

void set_random(double *matrix, int row, int column)
{
    // srand(time(NULL));
    for (int j = 0; j < column; j++)
    {
        for (int i = 0; i < row; i++)
        {
            matrix[j * row + i] = ((double)rand()) / RAND_MAX;
        }
    }
}

// set the initial values of a matrix/vector

void set_value(double *matrix, int row, int column, double value)
{
    for (int j = 0; j < column; j++)
    {
        for (int i = 0; i < row; i++)
        {
            matrix[j * row + i] = value;
        }
    }
}


// Print matrices/vectors

void print_vec_int(const char *name, const int n, int *X)
{
    printf("VECTOR (int) [%s] (%d x 1) is\n", name, n);
    for (int i = 0; i < n; ++i)
        printf("%d\t\n", X[i]);
    printf("\n");
}

void print_vec_float(const char *name, const int n, float *X)
{
    printf("VECTOR (float) [%s] (%d x 1) is\n", name, n);
    for (int i = 0; i < n; ++i)
        printf("%8.5f\t\n", X[i]);
    printf("\n");
}

void print_mat_float(const char *name, int row, int column, float *A, char *mode)
{
    printf("MATRIX (float) [%s] (%d x %d) is\n", name, row, column);
    char mode_row[3] = "row";
    char mode_col[3] = "col";
    
    if ((strncmp(mode, mode_row, sizeof(mode_row)) == 0) || (mode[0] == 'r'))
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                printf("%8.5f\t", A[i * column + j]);
            }
            printf("\n");
        }
    }
    else if ((strncmp(mode, mode_col, sizeof(mode_col)) == 0) || (mode[0] == 'c')) {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                printf("%8.5f\t", A[j * row + i]);
            }
            printf("\n");
        }
    }
    else
        printf("error: undefined matrix storage mode/format!");
    
    printf("\n");
}

void print_vec_double(const char *name, const int n, double *X)
{
    printf("VECTOR (double) [%s] (%d x 1) is\n", name, n);
    for (int i = 0; i < n; ++i)
        printf("%8.5f\t\n", X[i]);
    printf("\n");
}

void print_mat_double(const char *name, int row, int column, double *A, char *mode)
{
    printf("MATRIX (double) [%s] (%d x %d) is\n", name, row, column);
    char mode_row[3] = "row";
    char mode_col[3] = "col";
    
    if ((strncmp(mode, mode_row, sizeof(mode_row)) == 0) || (mode[0] == 'r'))
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                printf("%8.5f\t", A[i * column + j]);
            }
            printf("\n");
        }
    }
    else if ((strncmp(mode, mode_col, sizeof(mode_col)) == 0) || (mode[0] == 'c')) {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                printf("%8.5f\t", A[j * row + i]);
            }
            printf("\n");
        }
    }
    else
        printf("error: undefined matrix storage mode/format!");
    
    printf("\n");
}

void print_vec_complex(const char *name, const int n, complex *X)
{
    printf("VECTOR (complex) [%s] (%d x 1) is\n", name, n);
	for (int i = 0; i < n; ++i)
		printf("%8.5f + %8.5fj\t\n", X[i].real, X[i].imag);
    printf("\n");
}

void print_mat_complex(const char *name, int row, int column, complex *A, char *mode)
{
    printf("MATRIX (complex) [%s] (%d x %d) is\n", name, row, column);
    char mode_row[3] = "row";
    char mode_col[3] = "col";
    
    if ((strncmp(mode, mode_row, sizeof(mode_row)) == 0) || (mode[0] == 'r'))
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                printf("%8.5f + %8.5fj\t", A[i * column + j].real, A[i * column + j].imag);
            }
            printf("\n");
        }
    }
    else if ((strncmp(mode, mode_col, sizeof(mode_col)) == 0) || (mode[0] == 'c')) {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                printf("%8.5f + %8.5fj\t", A[j * row + i].real, A[j * row + i].imag);
            }
            printf("\n");
        }
    }
    else
        printf("error: undefined matrix storage mode/format!");
    
    printf("\n");
}

void print_vec_complex16(const char *name, const int n, complex16 *X)
{
    printf("VECTOR (complex16) [%s] (%d x 1) is\n", name, n);
	for (int i = 0; i < n; ++i)
		printf("(%8.5f, %8.5f)\t\n", X[i].real, X[i].imag);
    printf("\n");
}

void print_mat_complex16(const char *name, int row, int column, complex16 *A, char *mode)
{
    printf("MATRIX (complex16) [%s] (%d x %d) is\n", name, row, column);

    char mode_row[3] = "row";
    char mode_col[3] = "col";
    
    if ((strncmp(mode, mode_row, sizeof(mode_row)) == 0) || (mode[0] == 'r'))
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                printf("(%8.5f, %8.5f)\t", A[i * column + j].real, A[i * column + j].imag);
            }
            printf("\n");
        }
    }
    else if ((strncmp(mode, mode_col, sizeof(mode_col)) == 0) || (mode[0] == 'c')) {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                printf("(%8.5f, %8.5f)\t", A[j * row + i].real, A[j * row + i].imag);
            }
            printf("\n");
        }
    }
    else
        printf("error: undefined matrix storage mode/format!");
    
    printf("\n");
}

#define printm(row, column, A) print_mat(#A, row, column, A, "col")
#define printm2(row, column, A, mode) print_mat(#A, row, column, A, mode)
#define printv(row, A) print_vec(#A, row, A)

// #define print_mat(name, row, column, A) _Generic((0,A), float*: print_mat_float, \
//                                                       double*: print_mat_double, \
//                                                       complex*: print_mat_complex,\
//                                                       complex16*: print_mat_complex16)(name, row, column, A)

// #define print_vec(name, row, A) _Generic((0,A), float*: print_vec_float, \
//                                                       double*: print_vec_double, \
//                                                       complex*: print_vec_complex,\
//                                                       complex16*: print_vec_complex16)(name, row, A)

#define print_mat(name, row, column, A, mode) _Generic(&*(A), float*: print_mat_float, \
                                                      double*: print_mat_double, \
                                                      complex*: print_mat_complex,\
                                                      complex16*: print_mat_complex16)(name, row, column, A, mode)

#define print_vec(name, row, A) _Generic(&*(A), int*: print_vec_int, \
                                                float*: print_vec_float, \
                                                double*: print_vec_double, \
                                                complex*: print_vec_complex,\
                                                complex16*: print_vec_complex16)(name, row, A)

// compute the transpose of a square matrix A and store it in A.
void mtx_transpose_float(float *a, const int row, const int col)
{
	float *tmp = (float *) malloc(row * col * sizeof(float));

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			tmp[i * col + j] = a[i * col + j];

	for (int i=0; i < row; i++)
		for (int j=0; j < col; j++)
			a[j * row + i] = tmp[i * col + j];

    free(tmp);
}

// compute the transpose of a square matrix A and store it in A.
void mtx_transpose_double(double *a, const int row, const int col)
{
	double *tmp = (double *) malloc(row * col * sizeof(double));

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			tmp[i * col + j] = a[i * col + j];

	for (int i=0; i < row; i++)
		for (int j=0; j < col; j++)
			a[j * row + i] = tmp[i * col + j];

    free(tmp);
}

// compute the transpose of a square matrix A and store it in A.
void mtx_transpose_complex(complex *a, const int row, const int col)
{
	complex *tmp = (complex *) malloc(row * col * sizeof(complex));

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++){
			tmp[i * col + j].real = a[i * col + j].real;
			tmp[i * col + j].imag = a[i * col + j].imag;
        }

	for (int i=0; i < row; i++)
		for (int j=0; j < col; j++){
			a[j * row + i].real = tmp[i * col + j].real;
			a[j * row + i].imag = tmp[i * col + j].imag;
        }

    free(tmp);
}

// compute the transpose of a square matrix A and store it in A.
void mtx_transpose_complex16(complex16 *a, const int row, const int col)
{
	complex16 *tmp = (complex16 *) malloc(row * col * sizeof(complex16));

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++){
			tmp[i * col + j].real = a[i * col + j].real;
			tmp[i * col + j].imag = a[i * col + j].imag;
        }

	for (int i=0; i < row; i++)
		for (int j=0; j < col; j++){
			a[j * row + i].real = tmp[i * col + j].real;
			a[j * row + i].imag = tmp[i * col + j].imag;
        }

    free(tmp);
}

// #define mtx_transpose(A, row, col) _Generic((0,A), float*: mtx_transpose_float, \
//                                                 double*: mtx_transpose_double, \
//                                                 complex*: mtx_transpose_complex,\
//                                                 complex16*: mtx_transpose_complex16)(A, row, col)

#define mtx_transpose(A, row, col) _Generic(&*(A), float*: mtx_transpose_float, \
                                                double*: mtx_transpose_double, \
                                                complex*: mtx_transpose_complex,\
                                                complex16*: mtx_transpose_complex16)(A, row, col)


// compute the transpose of a square matrix A and store it in A.
void mtx_copy(double *a, double *a_copy, const int row, const int col)
{
	for (int i = 0; i < row * col; i++)
		a_copy[i] = a[i];
}


/* Get the name of a type */
#define typename(x) _Generic(&*(x), _Bool: "_Bool", \
    char: "char", \
    signed char: "signed char", \
    unsigned char: "unsigned char", \
    short int: "short int", \
    unsigned short int: "unsigned short int", \
    int: "int", \
    unsigned int: "unsigned int", \
    long int: "long int", \
    unsigned long int: "unsigned long int", \
    long long int: "long long int", \
    unsigned long long int: "unsigned long long int", \
    float: "float", \
    double: "double", \
    long double: "long double", \
    char *: "pointer to char", \
    void *: "pointer to void", \
    int *: "pointer to int", \
    default: "other")

#define printf_dec_format(x) _Generic((0,x), \
    char: "%c", \
    signed char: "%hhd", \
    unsigned char: "%hhu", \
    signed short: "%hd", \
    unsigned short: "%hu", \
    signed int: "%d", \
    unsigned int: "%u", \
    long int: "%ld", \
    unsigned long int: "%lu", \
    long long int: "%lld", \
    unsigned long long int: "%llu", \
    float: "%f", \
    double: "%f", \
    long double: "%Lf", \
    char *: "%s", \
    void *: "%p")

#define print(x) printf(printf_dec_format(x), x);
#define printnl(x) printf(printf_dec_format(x), x), printf("\n");

double wallclock()
{
  struct timeval tt;
  gettimeofday(&tt, NULL);

  double r = tt.tv_sec + 0.000001 * (double)tt.tv_usec;
  return (r);
}

double cputime()
{
  struct tms b;
  clock_t r;

  times(&b);
  r = b.tms_utime + b.tms_stime;
  return ((double)r / (double)sysconf(_SC_CLK_TCK));
}

#endif
