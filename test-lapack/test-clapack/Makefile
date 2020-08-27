

# define compiler and compiler flag variables
CC		= gcc
CXX		= g++
CFLAGS = -O3 -Wall
CPPFLAGS = -O3 -Wall -std=c++11
LDFLAGS = -lm -lrt -lgfortran

LDINC = -I$(CLAPACK_DIR)/include
EXTRA_LDFLAGS = -L$(CLAPACK_DIR)/lib -lclapack -lrefblas -lf2c

EXTRA_INC = -I./common
EXTRA_LIB = ./common/blaio.c

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
	$(CC) $(CFLAGS) $(LDINC) $(EXTRA_INC) -o $@ $< $(EXTRA_LDFLAGS) $(EXTRA_LIB) $(LDFLAGS)
	@rm $<
	./$@ > $@.txt
	@echo

.c.o:
	@echo '====================================='
	@echo 'Compile and execute: ' $<
	$(CC) $(CFLAGS) -c $< $(LDINC) $(EXTRA_INC)
.cpp.o:
	@echo '====================================='
	@echo 'Compile and execute: ' $<
	$(CXX) $(CPPFLAGS) -c $< $(LDINC) $(EXTRA_INC)

clean:
	rm -rf *.o $(TARGETS)
