#ifndef MY_UTILS_H
#define MY_UTILS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// complex data types

typedef struct
{
    float real, imag;
} complex;

typedef struct
{
    double real, imag;
} complex16;

void set_random(float *matrix, int row, int column);
void set_random(double *matrix, int row, int column);

// set the initial values of a matrix/vector

void set_value(float *matrix, int row, int column, float value);
void set_value(double *matrix, int row, int column, double value);

// Print matrices/vectors

void print_vector(char const *name, const int n, float *X);
void print_vector(char const *name, const int n, double *X);

void print_matrix(char const *name, int row, int column, float *A);
void print_matrix(char const *name, int row, int column, double *A);

void print_vector_complex(char const *name, const int n, complex *X);
void print_vector_complex(char const *name, const int n, complex16 *X);

void print_matrix_complex(char const *name, int row, int column, complex *A);
void print_matrix_complex(char const *name, int row, int column, complex16 *A);

// compute the transpose of a square matrix A and store it in the same matrix A.
void transpose(complex *a, const int row, const int col);
void transpose(complex16 *a, const int row, const int col);

void transpose_complex(complex *a, const int row, const int col);
void transpose_complex(complex16 *a, const int row, const int col);

// copy vectors or matrix.
void copy(float *a, float *a_copy, const int row, const int col);
void copy(double *a, double *a_copy, const int row, const int col);

void copy_complex(complex *a, complex *a_copy, const int row, const int col);
void copy_complex(complex16 *a, complex16 *a_copy, const int row, const int col);

// Print a vector with its name and location
#define F77_CALL(x)  #x

#define print_v(name, size) print_vector(F77_CALL(name), (const int) size, name)

#define print_vc(name, size) print_vector_complex(#name, size, name)

#define print_m(name, row, column) print_matrix(#name, row, column, name)
#define print_mc(name, row, column) print_matrix_complex(#name, row, column, name)

#endif
