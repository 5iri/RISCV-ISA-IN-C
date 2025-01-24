#include "riscv.h"

int32_t alu(int32_t operand1, int32_t operand2, Operation operation) {
    switch (operation) {
        case OP_ADD:
            return operand1 + operand2;
        case OP_ADDI:
            return operand1 + operand2;
        default:
            return 0; // Unknown operation
    }
}