# define compiler and compiler flag variables
CC		= gcc
CFLAGS 	= -O3 -Wall
CPPFLAGS= -O3 -Wall -std=c++11

LIBHOME = $(HOME)/matrix-library/lapack/3.8.0
BLASLIB    = $(LIBHOME)/lib64/libblas.a
CBLASLIB   = $(LIBHOME)/lib64/libcblas.a
LIBS := -L$(LIBHOME)/lib64
INC	:=  -I$(LIBHOME)/include

# LDFLAGS :=  $(CBLASLIB) $(BLASLIB)
LDFLAGS := -lm -lrt $(LIBS) -lcblas -lblas -lgfortran 
CFLAGS = -O3 -Wall $(INC) #	-m64 -fPIC 

# define source folder (src or .) and its content
SRCDIR	= .
TESTNAME = test-dgemm

# find all other file names or specify them
# SRCS := $(shell find $(SRCDIR) -name '*.c' -or -name '*.cpp')
SRCS = $(SRCDIR)/$(TESTNAME)

SRCOBJS = $(SRCS:%.c=$(SRCDIR)/%.o)
TARGETS := $(patsubst %.o,%,$(SRCOBJS))

default: $(TARGETS)
	@echo Make Complete

# pattern rules to compile objectives
$(TARGETS): %: %.o
	$(CC) $(CFLAGS) -o $@ $< $(CBLAS_FLAGS) $(LDFLAGS)
	rm $<
	./$@ > $@.out

.c.o:
	@echo ===================== $@ ===========================
	$(CC) $(CFLAGS) -c $<
.cpp.o:
	@echo ===================== $@ ===========================
	$(CC) $(CPPFLAGS) -c $<

clean:
	rm -rf *.o $(TARGETS_RUN)
