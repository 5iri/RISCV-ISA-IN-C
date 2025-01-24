#include "riscv.h"

Operation get_operation(DecodedInstruction decoded) {
    switch (decoded.opcode) {
        case 0x13: // I-type (e.g., ADDI)
            return OP_ADDI;
        case 0x33: // R-type (e.g., ADD)
            if (decoded.funct3 == 0x0 && decoded.funct7 == 0x00) {
                return OP_ADD;
            }
            break;
        default:
            break;
    }
    return OP_UNKNOWN;
}