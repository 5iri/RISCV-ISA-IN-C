#include "riscv.h"

// Decode I-type instruction
ITypeInstruction decodeIType(uint32_t instr) {
    ITypeInstruction iType;
    iType.opcode = instr & 0x7F;
    iType.rd = (instr >> 7) & 0x1F;
    iType.funct3 = (instr >> 12) & 0x7;
    iType.rs1 = (instr >> 15) & 0x1F;
    iType.imm = (int32_t)(instr & 0xFFF00000) >> 20; // Sign-extend the immediate
    return iType;
}

// Decode R-type instruction
RTypeInstruction decodeRType(uint32_t instr) {
    RTypeInstruction rType;
    rType.opcode = instr & 0x7F;
    rType.rd = (instr >> 7) & 0x1F;
    rType.funct3 = (instr >> 12) & 0x7;
    rType.rs1 = (instr >> 15) & 0x1F;
    rType.rs2 = (instr >> 20) & 0x1F;
    rType.funct7 = (instr >> 25) & 0x7F;
    return rType;
}

// Decode S-type instruction
STypeInstruction decodeSType(uint32_t instr) {
    STypeInstruction sType;
    sType.opcode = instr & 0x7F;
    sType.funct3 = (instr >> 12) & 0x7;
    sType.rs1 = (instr >> 15) & 0x1F;
    sType.rs2 = (instr >> 20) & 0x1F;
    sType.imm = (int32_t)(((instr >> 25) << 5) | ((instr >> 7) & 0x1F)) << 20 >> 20; // Sign-extend the immediate
    return sType;
}

// Decode U-type instruction
UTypeInstruction decodeUType(uint32_t instr) {
    UTypeInstruction uType;
    uType.opcode = instr & 0x7F;
    uType.rd = (instr >> 7) & 0x1F;
    uType.imm = (int32_t)(instr & 0xFFFFF000); // Immediate is in the upper 20 bits
    return uType;
}

// Decode J-type instruction
JTypeInstruction decodeJType(uint32_t instr) {
    JTypeInstruction jType;
    jType.opcode = instr & 0x7F;
    jType.rd = (instr >> 7) & 0x1F;
    jType.imm = (int32_t)((instr & 0x80000000) ? 0xFFF00000 : 0) | // Sign-extend
                ((instr >> 20) & 0x7FE) |                         // imm[10:1]
                ((instr >> 9) & 0x800) |                          // imm[11]
                ((instr >> 12) & 0xFF);                           // imm[19:12]
    return jType;
}


// General decoder function
DecodedInstruction decode(uint32_t instr) {
    DecodedInstruction decoded;
    uint8_t opcode = instr & 0x7F;

    switch (opcode) {
        case 0x13: // I-type (e.g., addi)
        case 0x03: // I-type (e.g., load instructions)
            {
                ITypeInstruction iType = decodeIType(instr);
                decoded.opcode = iType.opcode;
                decoded.rd = iType.rd;
                decoded.funct3 = iType.funct3;
                decoded.rs1 = iType.rs1;
                decoded.rs2 = 0; // Not used in I-type
                decoded.funct7 = 0; // Not used in I-type
                decoded.imm = iType.imm;
            }
            break;
        case 0x33: // R-type (e.g., add, sub)
            {
                RTypeInstruction rType = decodeRType(instr);
                decoded.opcode = rType.opcode;
                decoded.rd = rType.rd;
                decoded.funct3 = rType.funct3;
                decoded.rs1 = rType.rs1;
                decoded.rs2 = rType.rs2;
                decoded.funct7 = rType.funct7;
                decoded.imm = 0; // Not used in R-type

            }
            break;
        case 0x23: // S-type (e.g., store instructions)
            {
                STypeInstruction sType = decodeSType(instr);
                decoded.opcode = sType.opcode;
                decoded.rd = 0; // Not used in S-type
                decoded.funct3 = sType.funct3;
                decoded.rs1 = sType.rs1;
                decoded.rs2 = sType.rs2;
                decoded.funct7 = 0; // Not used in S-type
                decoded.imm = sType.imm;
            }
            break;
        case 0x37: // U-type (e.g., lui)
        case 0x17: // U-type (e.g., auipc)
            {
                UTypeInstruction uType = decodeUType(instr);
                decoded.opcode = uType.opcode;
                decoded.rd = uType.rd;
                decoded.funct3 = 0; // Not used in U-type
                decoded.rs1 = 0; // Not used in U-type
                decoded.rs2 = 0; // Not used in U-type
                decoded.funct7 = 0; // Not used in U-type
                decoded.imm = uType.imm;
            }
            break;
        case 0x6F: // J-type (e.g., jal)
            {
                JTypeInstruction jType = decodeJType(instr);
                decoded.opcode = jType.opcode;
                decoded.rd = jType.rd;
                decoded.funct3 = 0; // Not used in J-type
                decoded.rs1 = 0; // Not used in J-type
                decoded.rs2 = 0; // Not used in J-type
                decoded.funct7 = 0; // Not used in J-type
                decoded.imm = jType.imm;
            }
            break;
        default:
            // Handle unknown opcode
            decoded.opcode = opcode;
            decoded.rd = 0;
            decoded.funct3 = 0;
            decoded.rs1 = 0;
            decoded.rs2 = 0;
            decoded.funct7 = 0;
            decoded.imm = 0;
            break;
    }

    return decoded;
}