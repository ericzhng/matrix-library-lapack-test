####################################################################
#  BLAS make include file.                                         #
#  August, 27 2020                                                 #
#  Eric Zhang                                                      #
####################################################################

SHELL = /bin/sh

#  CC is the C compiler, normally invoked with options CFLAGS.
CC = gcc
CCP = g++
FC = gfortran

#  The location of the libraries to which you will link
LAPACK_HOME = $(HOME)/matrix-library/lapack/3.8.0

TMGLIB     = $(LAPACK_HOME)/lib64/libtmglib.a
BLASLIB    = $(LAPACK_HOME)/lib64/libblas.a
CBLASLIB   = $(LAPACK_HOME)/lib64/libcblas.a
LAPACKLIB  = $(LAPACK_HOME)/lib64/liblapack.a
LAPACKELIB = $(LAPACK_HOME)/lib64/liblapacke.a

LIBS := -L$(LAPACK_HOME)/lib64
INC	 := -I$(LAPACK_HOME)/include

LDFLAGS := $(LIBS) -llapacke -llapack -lcblas -lblas -lm -lrt -lgfortran
CFLAGS := -Wall -O3 $(INC) -Wno-missing-braces  -Wno-incompatible-pointer-types
