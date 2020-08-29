
include ../make.inc

# TESTNAME = test-gbmv
CC = g++
SRC_DIRS = .

# # SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.f -or -name *.f90)
SRCS := $(shell find $(SRC_DIRS) -type f \( -name "*.c" -o -name "*.cpp" \))
# SRCS = $(SRC_DIRS)/$(TESTNAME)

BUILD_DIR ?=.
OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)
PRGS := $(patsubst %.cpp,%,$(SRCS))
EXECUTABLES := $(patsubst %.out,./%,$(PRGS))

all: $(PRGS)

# list the libfoo rule as a dependency
$(PRGS): %: %.o
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) -lgfortran -std=c++11
	rm $<
	./$@

.cpp.o:
	@echo ===================== $@ ===========================
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rf $(PRGS) $(OBJS)
