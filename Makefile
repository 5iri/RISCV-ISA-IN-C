# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2

# Directories
SRC_DIR = src
BUILD_DIR = build

# Source files (relative to SRC_DIR)
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/memory.c $(SRC_DIR)/alu.c $(SRC_DIR)/control_unit.c $(SRC_DIR)/decoder.c $(SRC_DIR)/fetch.c $(SRC_DIR)/regfile.c $(SRC_DIR)/writeback.c

# Object files (relative to BUILD_DIR)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Executable name
TARGET = riscv_core

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile .c files into .o files in the BUILD_DIR
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)  # Ensure the build directory exists
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Phony targets (not actual files)
.PHONY: all clean