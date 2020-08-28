#ifndef MY_UTILS_H
#define MY_UTILS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void print_vec_float(const char *name, const int n, float *X)
{
    printf(" == Vector %s (%d X 1): == \n", name, n);
    for (int i = 0; i < n; ++i)
        printf("%f\n", X[i]);
    printf("\n");
}

void print_mat_float(const char *name, int row, int column, float *A)
{
    printf(" == Matrix %s (%d X %d): == \n", name, row, column);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf(" %.5f  ", A[j * row + i]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_vec_double(const char *name, const int n, double *X)
{
    printf(" == Vector %s (%d X 1): == \n", name, n);
    for (int i = 0; i < n; ++i)
        printf("%f\n", X[i]);
    printf("\n");
}

void print_mat_double(const char *name, int row, int column, double *A)
{
    printf(" == Matrix %s (%d X %d): == \n", name, row, column);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf(" %.5f  ", A[j * row + i]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_vec_complex(const char *name, const int n, complex *X)
{
    printf(" == Vector %s (%d X 1): == \n", name, n);
	for (int i = 0; i < n; ++i)
		printf("(%.5f, %.5f)\n", X[i].real, X[i].imag);
    printf("\n");
}

void print_mat_complex(const char *name, int row, int column, complex *A)
{
    printf(" == Matrix %s (%d X %d): == \n", name, row, column);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("(%.5f, %.5f)    ", A[j * row + i].real, A[j * row + i].imag);
        }
        printf("\n");
    }
    printf("\n");
}

void print_vec_complex16(const char *name, const int n, complex16 *X)
{
    printf(" == Vector %s (%d X 1): == \n", name, n);
	for (int i = 0; i < n; ++i)
		printf("(%.5f, %.5f)\n", X[i].real, X[i].imag);
    printf("\n");
}

void print_mat_complex16(const char *name, int row, int column, complex16 *A)
{
    printf(" == Matrix %s (%d X %d): == \n", name, row, column);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("(%.5f, %.5f)    ", A[j * row + i].real, A[j * row + i].imag);
        }
        printf("\n");
    }
    printf("\n");
}

#define print_mat(row, column, A) _Generic((A), float *: print_mat_float, \
                                                      double *: print_mat_double, \
                                                      complex *: print_mat_complex,\
                                                      complex16 *: print_mat_complex16)(#A, row, column, A)

#define print_vec(row, A) _Generic((A), float *: print_vec_float, \
                                                      double *: print_vec_double, \
                                                      complex *: print_vec_complex,\
                                                      complex16 *: print_vec_complex16)(#A, row, A)

// Print a vector with its name and location
#define PRINT_s(name, size) print_vec1(#name, name, size)
#define PRINT_d(name, size) print_vec2(#name, name, size)
#define PRINT_c(name, size) print_vec3(#name, name, size)
#define PRINT_z(name, size) print_vec4(#name, name, size)
void print_vec1(char *name, float value[], int size)	{ for (int i = 0; i < size; i++) printf("%s[%d] = %g\n", name, i + 1, value[i]); }
void print_vec2(char *name, double value[], int size)	{ for (int i = 0; i < size; i++) printf("%s[%d] = %g\n", name, i + 1, value[i]); }
void print_vec3(char *name, complex value[], int size)	{ for (int i = 0; i < size; i++) printf("%s[%d] = %g + 1j %g\n", name, i + 1, value[i].real, value[i].imag); }
void print_vec4(char *name, complex16 value[], int size)	{ for (int i = 0; i < size; i++) printf("%s[%d] = %g + 1j %g\n", name, i + 1, value[i].real, value[i].imag); }


// compute the transpose of a square matrix A and store it in A.
void mtx_transpose(double *a, const int row, const int col)
{
	double *tmp;
    tmp = malloc(row * col * sizeof(double));

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			tmp[i * col + j] = a[i * col + j];

	for (int i=0; i < row; i++)
		for (int j=0; j < col; j++)
			a[j * row + i] = tmp[i * col + j];

    free(tmp);
}

// compute the transpose of a square matrix A and store it in A.
void mtx_copy(double *a, double *a_copy, const int row, const int col)
{
	for (int i = 0; i < row * col; i++)
		a_copy[i] = a[i];
}

#endif
