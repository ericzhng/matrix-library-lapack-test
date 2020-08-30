
include ../make.inc

SRC_DIR := src
EXT_INC := -I./src/common
EXT_FLAGS := ./src/common/blaio.c

SRCS := $(shell find $(SRC_DIR) -maxdepth 1 -name '*.c' -or -name '*.cpp')
# TESTNAME = test-gbmv
# SRCS = $(SRC_DIR)/$(TESTNAME)

BUILD_DIR ?= exec
SRCOBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
TARGETS := $(patsubst %.o,%,$(SRCOBJS))
OUTFILES := $(patsubst %.o,%.txt,$(SRCOBJS))

all: create_dir $(TARGETS) 

# list the libfoo rule as a dependency
$(TARGETS): $(BUILD_DIR)/%: $(BUILD_DIR)/%.o
	@$(CC) $(CFLAGS) -o $@ $< $(EXT_INC) $(EXT_FLAGS) $(LDFLAGS)
	./$@ > $@.txt

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
	@echo ===================== $@ ===========================
	$(CC) $(CFLAGS) -c $< -o $@ $(EXT_INC)

clean :
	rm -rf $(TARGETS) $(SRCOBJS) $(OUTFILES)

create_dir:
	mkdir -p exec
echo:
	@echo $(SRCOBJS)
	@echo $(TARGETS)
