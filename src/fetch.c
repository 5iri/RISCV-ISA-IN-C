#include "riscv.h"

uint32_t fetch() {

    return memory[pc / 4]; // Assuming memory is word-aligned
}