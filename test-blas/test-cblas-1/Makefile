# define compiler and compiler flag variables
CC		= gcc
CFLAGS = -O3 -Wall
CPPFLAGS = -O3 -Wall -std=c++11
LDFLAGS = -lm -lrt -lgfortran

CBLAS_FLAGS	= $(CBLAS_LIB) $(BLAS_LIB)

# define source folder (src or .) and its content
SRCDIR	= .

# find all other file names or specify them
SUF  ?= .c
SRCS := $(shell find $(SRCDIR) -name '*$(SUF)' -or -name '*.cpp')
ifeq ($(SRCDIR),.)
SRCS1 = $(notdir $(SRCS))
endif
SRCOBJS = $(SRCS1:%.c=$(SRCDIR)/%.o)
TARGETS := $(patsubst %.o,%,$(SRCOBJS))

default: $(TARGETS)
	@echo Make Complete

# pattern rules to compile objectives
$(TARGETS): %: %.o
	$(CC) $(CFLAGS) $(LDINC) -o $@ $< $(CBLAS_FLAGS) $(LDFLAGS)
	rm $<
	./$@ > $@.out

.c.o:
	$(CC) $(CFLAGS) $(LDINC) -c $<
.cpp.o:
	$(CC) $(CPPFLAGS) $(LDINC) -c $<

clean:
	rm -rf *.o $(TARGETS_RUN)
