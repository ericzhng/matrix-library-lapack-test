

# define compiler and compiler flag variables
CC		= gcc
CFLAGS = -O3 -Wall
CPPFLAGS = -O3 -Wall -std=c++11
LDFLAGS = -lm -lrt -lgfortran


SOFTWARE_DIR = /home/ericzhng/software
LDINC = -I$(SOFTWARE_DIR)/blas/include
CBLAS_FLAGS	= $(CBLAS_LIB) $(BLAS_LIB)

EXTRAINC = -I./common
EXTRALIB = ./common/blaio.c


# define source folder (src or .) and its content
SRCDIR	= .

# find all other file names or specify them
SUF  ?= .c
SRCS := $(shell find $(SRCDIR) -maxdepth 1  -name '*$(SUF)' -or -name '*.cpp')
ifeq ($(SRCDIR),.)
SRCS1 = $(notdir $(SRCS))
endif
SRCOBJS = $(SRCS1:%.c=$(SRCDIR)/%.o)
TARGETS := $(patsubst %.o,%,$(SRCOBJS))

default: $(TARGETS)
	@echo Make Complete

# pattern rules to compile objectives
$(TARGETS): %: %.o
	$(CC) $(CFLAGS) $(LDINC) -o $@ $< $(CBLAS_FLAGS) $(EXTRAINC) $(EXTRALIB) $(LDFLAGS)
	rm $<
	./$@ > $@.txt

.c.o:
	$(CC) $(CFLAGS) $(LDINC) -c $< $(EXTRAINC)
.cpp.o:
	$(CC) $(CPPFLAGS) $(LDINC) -c $< $(EXTRAINC)

clean:
	rm -rf *.o $(TARGETS)
