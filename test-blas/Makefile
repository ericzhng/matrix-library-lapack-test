
SRC_DIRS ?= src/level-2
#SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.f -or -name *.f90)

SRCS = $(SRC_DIRS)/test-gerc

BUILD_DIR ?=.
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)
PRGS := $(patsubst %.c,%,$(SRCS))
EXECUTABLES := $(patsubst %,./%,$(PRGS))

FC		= gfortran
CC		= gcc
CFLAGS_INC :=
BLASLIB1 := -L$(HOME)/matrix-library/lapack/3.8.0/lib64 -lblas
CFLAGS	:= -Wall -O3 $(CFLAGS_INC)
LDFLAGS := $(BLASLIB1) -lgfortran -lm -lrt

all: $(PRGS)

# list the libfoo rule as a dependency
$(PRGS): %: %.o
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)
	rm $<
	./$@

clean :
	rm -rf $(PRGS) $(OBJS)
