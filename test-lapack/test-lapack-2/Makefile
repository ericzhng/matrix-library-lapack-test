

# define compiler and compiler flag variables
CC		= gcc
CXX		= g++
CFLAGS = -O3 -Wall -Wno-comment
CPPFLAGS = -O3 -Wall -std=c++11
LDFLAGS = -lm -lrt -lgfortran

LDINC = -I$(LAPACKDIR)/include -I$(BLASDIR)/include
EXTRA_LDFLAGS = -L$(LAPACKDIR)/lib -llapack-eric -L$(BLASDIR)/lib  -lcblas-eric -lblas-eric

EXTRA_INC = -I./common
EXTRA_LIB = ./common/blaio.c

# define source folder (src or .) and its content
SRCDIR	= src

# find all other file names or specify them
SUF  := .c
SRCS := $(shell find $(SRCDIR) -maxdepth 1 -name '*$(SUF)')
ifeq ($(SRCDIR),.)
SRCS1 = $(notdir $(SRCS))
else
SRCS1 = $(SRCS)
endif
SRCOBJS = $(SRCS1:%.c=%.o)
TARGETS := $(patsubst %.o,%,$(SRCOBJS))

default: $(TARGETS)
	@echo Make Complete

print:
	@echo $(SUF)
	@echo $(SRCS)
	@echo $(SRCS1)
	@echo $(SRCOBJS)
	@echo $(TARGETS)

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
