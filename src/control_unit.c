#include "riscv.h"

void get_operation(DecodedInstruction decoded) {
    switch (decoded.opcode) {
        case 0x13: // I-type (e.g., ADDI)
            reg[decoded.rd] = alu( reg[decoded.rs1], decoded.imm, OP_ADDI);
            break;
        case 0x33: // R-type (e.g., ADD)
            if (decoded.funct3 == 0x0 && decoded.funct7 == 0x00) {
                reg[decoded.rd] = alu(reg[decoded.rs1], reg[decoded.rs2], OP_ADD);
            }
            break;
        default:
            break;
    }
}