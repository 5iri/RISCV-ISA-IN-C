#include "riscv.h"

DecodedInstruction decode(uint32_t instr) {
    DecodedInstruction decoded;
    decoded.opcode = instr & 0x7F;
    decoded.rd = (instr >> 7) & 0x1F;
    decoded.funct3 = (instr >> 12) & 0x7;
    decoded.rs1 = (instr >> 15) & 0x1F;
    decoded.rs2 = (instr >> 20) & 0x1F;
    decoded.funct7 = (instr >> 25) & 0x7F;

    // Handle immediate values (I-type, S-type)
    if (decoded.opcode == 0x13 || decoded.opcode == 0x03) { // I-type (e.g., addi)
        // Extract the lower 12 bits and sign-extend
        decoded.imm = (int32_t)(instr & 0xFFF00000) >> 20;
    } else if (decoded.opcode == 0x23) { // S-type (e.g., store instructions)
        // Extract the immediate and sign-extend
        decoded.imm = (int32_t)(((instr >> 25) << 5) | ((instr >> 7) & 0x1F)) << 20 >> 20;
    } else {
        decoded.imm = 0;
    }

    return decoded;
}
