
include ../make.inc

TESTNAME = test-gbmv

SRC_DIRS = .

# # SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.f -or -name *.f90)
SRCS := $(shell find $(SRC_DIRS)/ -name "*.c")
# SRCS = $(SRC_DIRS)/$(TESTNAME)

BUILD_DIR ?=.
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)
PRGS := $(patsubst %.c,%,$(SRCS))
EXECUTABLES := $(patsubst %.out,./%,$(PRGS))

all: $(PRGS)

# list the libfoo rule as a dependency
$(PRGS): %: %.o
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) -lgfortran
	rm $<
	./$@

.c.o:
	@echo ===================== $@ ===========================
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rf $(PRGS) $(OBJS)
