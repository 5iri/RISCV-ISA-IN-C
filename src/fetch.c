#include "riscv.h"

uint32_t fetch() {
    return memory[pc / 4]; // Assume word-aligned memory
}