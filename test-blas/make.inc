####################################################################
#  BLAS make include file.                                         #
#  August, 27 2020                                                 #
#  Eric Zhang                                                      #
####################################################################

SHELL = /bin/sh

#  CC is the C compiler, normally invoked with options CFLAGS.
CC = gcc
FC = gfortran

#  The location of the libraries to which you will link.  (The
#  machine-specific, optimized BLAS library should be used whenever
#  possible.)

LIBHOME = $(HOME)/matrix-library/lapack/3.8.0

TMGLIB     = $(LIBHOME)/lib64/libtmglib.a
BLASLIB    = $(LIBHOME)/lib64/libblas.a
CBLASLIB   = $(LIBHOME)/lib64/libcblas.a
LAPACKLIB  = $(LIBHOME)/lib64/liblapack.a
LAPACKELIB = $(LIBHOME)/lib64/liblapacke.a

LIBS := -L$(LIBHOME)/lib64
INC	:=  -I$(LIBHOME)/include -I../header

LDFLAGS := $(LIBS) -lblas
CFLAGS = -Wall -O3 -m64 -fPIC $(INC)
