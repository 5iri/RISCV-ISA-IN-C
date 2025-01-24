# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2

# Source files
SRCS = main.c memory.c alu.c control_unit.c decoder.c fetch.c regfile.c writeback.c

# Object files (automatically generated from source files)
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = riscv_core

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets (not actual files)
.PHONY: all clean
