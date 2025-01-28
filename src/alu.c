#include "riscv.h"

int32_t alu(int32_t operand1, int32_t operand2, Operation operation) {
    switch (operation) {
        case OP_ADD:
            return operand1 + operand2;
        case OP_ADDI:
            return operand1 + operand2;
        case OP_SUB:
            return operand1 - operand2;
        case OP_SLL:
            return operand1 << (operand2 & 0x1F);
        case OP_SLLI:
            return operand1 << (operand2 & 0x1F);
        case OP_SLT:
            return (operand1 < operand2) ? 1 : 0;
        case OP_SLTI:
            return (operand1 < operand2) ? 1 : 0;
        case OP_SLTU:
            return ((uint32_t)operand1 < (uint32_t)operand2) ? 1 : 0;
        case OP_SLTIU:
            return ((uint32_t)operand1 < (uint32_t)operand2) ? 1 : 0;
        case OP_XOR:
            return operand1 ^ operand2;
        case OP_XORI:
            return operand1 ^ operand2;
        case OP_OR:
            return operand1 | operand2;
        case OP_ORI:
            return operand1 | operand2;
        case OP_AND:
            return operand1 & operand2;
        case OP_ANDI:
            return operand1 & operand2;
        case OP_SRL:
            return (uint32_t)operand1 >> (operand2 & 0x1F);
        case OP_SRLI:
            return (uint32_t)operand1 >> (operand2 & 0x1F);
        case OP_SRA:
            return operand1 >> (operand2 & 0x1F);
        case OP_SRAI:
            return operand1 >> (operand2 & 0x1F);
        case OP_LUI:
            return operand2; // operand2 represents the immediate in LUI
        case OP_AUIPC:
            return operand1 + operand2; // operand1 is PC, operand2 is immediate
        case OP_BEQ:
            return (operand1 == operand2) ? 1 : 0;
        case OP_BNE:
            return (operand1 != operand2) ? 1 : 0;
        case OP_BLT:
            return (operand1 < operand2) ? 1 : 0;
        case OP_BGE:
            return (operand1 >= operand2) ? 1 : 0;
        case OP_BLTU:
            return ((uint32_t)operand1 < (uint32_t)operand2) ? 1 : 0;
        case OP_BGEU:
            return ((uint32_t)operand1 >= (uint32_t)operand2) ? 1 : 0;
        default:
            return 0; // Unknown operation
    }
}
