

# define compiler and compiler flag variables
CC		= gcc
CXX		= g++
CFLAGS = -O3 -Wall -Wno-unused-variable
CPPFLAGS = -O3 -Wall -std=c++11
LDFLAGS = -lm -lrt -lgfortran

LDINC = -I$(LAPACK_DIR)/include  -I$(BLAS_DIR)/include
EXTRA_LDFLAGS = -L$(LAPACK_DIR)/lib -llapacke-eric -llapack-eric -L$(BLAS_DIR)/lib -lcblas-eric -lblas-eric -ltmglib-eric

EXTRA_INC = -I./common
EXTRA_LIB = ./common/blaio.c ./common/lapacke_example_aux.c

# define source folder (src or .) and its content
SRCDIR	= src

# find all other file names or specify them
SUF  = .c
SRCS := $(shell find $(SRCDIR) -maxdepth 1  -name '*$(SUF)' -or -name '*.cpp')
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
	@rm $<
	./$@ > $@.txt
	@echo

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
