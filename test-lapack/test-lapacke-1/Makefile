

# define compiler and compiler flag variables
CC		= gcc
CXX		= g++

CFLAGS = -O3 -Wall -Wno-comment -Wno-missing-braces -Wno-incompatible-pointer-types
CPPFLAGS = -O3 -Wall -std=c++11
LDFLAGS = -lrt -lgfortran -lm

LDINC = -I$(LAPACK_DIR)/include  -I$(BLAS_DIR)/include
EXTRA_LDFLAGS = -L$(LAPACK_DIR)/lib -llapacke-eric -llapack-eric -L$(BLAS_DIR)/lib -lcblas-eric -lblas-eric -ltmglib-eric

#$(LAPACK_DIR)/lib/liblapacke-eric.a

#EXTRA_INC = -I./common
#EXTRA_LIB = ./common/blaio.c
EXTRA_INC = 
EXTRA_LIB =

# define source folder (src or .) and its content
SRCDIR	= src

# find all other file names or specify them
SUF1  ?= .c
SRCS := $(shell find $(SRCDIR) -maxdepth 1  -name '*$(SUF1)' -or -name '*.cpp')

SRCS=src/test-dptsv.c

ifeq ($(SRCDIR),.)
SRCS1 = $(notdir $(SRCS))
else
SRCS1 = $(SRCS)
endif
SRCOBJS = $(SRCS1:%.c=%.o)
TARGETS := $(patsubst %.o,%,$(SRCOBJS))

default: $(TARGETS)
	@echo Make Complete

# pattern rules to compile objectives
$(TARGETS): %: %.o
	$(CC) $(CFLAGS) $(LDINC) $(EXTRA_INC) -o $@ $< $(EXTRA_LDFLAGS) $(EXTRA_LIB) $(LDFLAGS)
	@echo
	@rm $<
	./$@

.c.o:
	@echo '====================================='
	@echo 'Compile and execute: ' $<
	$(CC) $(CFLAGS) -c $< -o $@ $(LDINC) $(EXTRA_INC)
.cpp.o:
	@echo '====================================='
	@echo 'Compile and execute: ' $<
	$(CXX) $(CPPFLAGS) -c $< -o $@ $(LDINC) $(EXTRA_INC)

clean:
	rm -rf *.o $(TARGETS)
