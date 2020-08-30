# define compiler and compiler flag variables
CC		= gcc

LIBHOME = $(HOME)/matrix-library/lapack/3.8.0
BLASLIB    = $(LIBHOME)/lib64/libblas.a
CBLASLIB   = $(LIBHOME)/lib64/libcblas.a
LIBS := -L$(LIBHOME)/lib64
INC	:=  -I$(LIBHOME)/include -I./common_no_enum

EXTRALIB = ./common_no_enum/blaio.c

LDFLAGS := -lm -lrt $(LIBS) -lcblas -lblas -lgfortran 
CFLAGS = -O3 -Wall $(INC)

# define source folder (src or .) and its content
# TESTNAME = test-dgemm-f77

# find all other file names or specify them
SRCDIR	= .
SRCS := $(shell find $(SRCDIR) -maxdepth 1 -name '*.c' -or -name '*.cpp')
# SRCS = $(SRCDIR)/$(TESTNAME)

SRCOBJS = $(SRCS:%.c=$(SRCDIR)/%.o)
TARGETS := $(patsubst %.o,%,$(SRCOBJS))

default: $(TARGETS)
	@echo Make Complete

# pattern rules to compile objectives
$(TARGETS): %: %.o
	$(CC) $(CFLAGS) -o $@ $< $(EXTRALIB) $(LDFLAGS)
	rm $<
	./$@

# > $@.out

.c.o:
	@echo ===================== $@ ===========================
	$(CC) $(CFLAGS) -c $<
.cpp.o:
	@echo ===================== $@ ===========================
	$(CC) $(CPPFLAGS) -c $<

clean:
	rm -rf *.o $(TARGETS)
