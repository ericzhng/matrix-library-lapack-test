
#include "utilities.h"

#include <stdio.h>
#include <string.h>

// initialize a matrix/vector with random double values

void set_random(float *matrix, int row, int column)
{
    // srand(time(NULL));
    for (int j = 0; j < column; j++)
    {
        for (int i = 0; i < row; i++)
        {
            matrix[j * row + i] = ((float)rand()) / RAND_MAX;
        }
    }
}

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

void set_value(double *matrix, int row, int column, float value)
{
    for (int j = 0; j < column; j++)
    {
        for (int i = 0; i < row; i++)
        {
            matrix[j * row + i] = value;
        }
    }
}

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

void print_vector(char const *name, const int n, float *X)
{
    printf(" == Vector %s (%d X 1): == \n", name, n);
    for (int i = 0; i < n; ++i)
        printf("%f\n", X[i]);
    printf("\n");
}
void print_vector(char const *name, const int n, double *X)
{
    printf(" == Vector %s (%d X 1): == \n", name, n);
    for (int i = 0; i < n; ++i)
        printf("%f\n", X[i]);
    printf("\n");
}

void print_matrix(char const *name, int row, int column, float *A)
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

void print_matrix(char const *name, int row, int column, double *A)
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

void print_vector_complex(char const *name, const int n, complex *X)
{
    printf(" == Vector %s (%d X 1): == \n", name, n);
    for (int i = 0; i < n; ++i)
        printf("(%.5f, %.5f)\n", X[i].real, X[i].imag);
    printf("\n");
}

void print_vector_complex(char const *name, const int n, complex16 *X)
{
    printf(" == Vector %s (%d X 1): == \n", name, n);
    for (int i = 0; i < n; ++i)
        printf("(%.5f, %.5f)\n", X[i].real, X[i].imag);
    printf("\n");
}

void print_matrix_complex(char const *name, int row, int column, complex *A)
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

void print_matrix_complex(char const *name, int row, int column, complex16 *A)
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


// compute the transpose of a square matrix A and store it in the same matrix A.

void transpose(float *a, const int row, const int col)
{
    float *tmp = new float[row * col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            tmp[i * col + j] = a[i * col + j];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            a[j * row + i] = tmp[i * col + j];

    delete[] tmp;
}

void transpose(double *a, const int row, const int col)
{
    double *tmp = new double[row * col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            tmp[i * col + j] = a[i * col + j];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            a[j * row + i] = tmp[i * col + j];

    delete[] tmp;
}


void transpose_complex(complex *a, const int row, const int col)
{
    complex *tmp = new complex[row * col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            tmp[i * col + j] = a[i * col + j];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            a[j * row + i] = tmp[i * col + j];

    delete[] tmp;
}

void transpose_complex(complex16 *a, const int row, const int col)
{
    complex16 *tmp = new complex16[row * col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            tmp[i * col + j] = a[i * col + j];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            a[j * row + i] = tmp[i * col + j];

    delete[] tmp;
}


// copy vectors or matrix.
template <typename T>
void copy(T *a, T *a_copy, const int row, const int col = 1)
{
    for (int i = 0; i < row * col; i++)
        a_copy[i] = a[i];
}

template <typename T>
void copy_complex(T *a, T *a_copy, const int row, const int col = 1)
{
    for (int i = 0; i < row * col; i++)
    {
        a_copy[i].real = a[i].real;
        a_copy[i].imag = a[i].imag;
    }
}
