#include "riscv.h"

void get_operation(DecodedInstruction decoded) {
    switch (decoded.opcode) {
        case 0x13: // I-type instructions
            switch (decoded.funct3) {
                case 0x0: // ADDI
                    reg[decoded.rd] = alu(reg[decoded.rs1], decoded.imm, OP_ADDI);
                    break;
                case 0x2: // SLTI
                    reg[decoded.rd] = alu(reg[decoded.rs1], decoded.imm, OP_SLTI);
                    break;
                case 0x3: // SLTIU
                    reg[decoded.rd] = alu(reg[decoded.rs1], decoded.imm, OP_SLTIU);
                    break;
                case 0x4: // XORI
                    reg[decoded.rd] = alu(reg[decoded.rs1], decoded.imm, OP_XORI);
                    break;
                case 0x6: // ORI
                    reg[decoded.rd] = alu(reg[decoded.rs1], decoded.imm, OP_ORI);
                    break;
                case 0x7: // ANDI
                    reg[decoded.rd] = alu(reg[decoded.rs1], decoded.imm, OP_ANDI);
                    break;
                case 0x1: // SLLI (shift immediate left)
                    reg[decoded.rd] = alu(reg[decoded.rs1], decoded.imm, OP_SLLI);
                    break;
                case 0x5: // SRLI or SRAI
                    if (decoded.funct7 == 0x00) { // SRLI (logical shift right)
                        reg[decoded.rd] = alu(reg[decoded.rs1], decoded.imm, OP_SRLI);
                    } else if (decoded.funct7 == 0x20) { // SRAI (arithmetic shift right)
                        reg[decoded.rd] = alu(reg[decoded.rs1], decoded.imm, OP_SRAI);
                    }
                    break;
            }
            break;
        case 0x33: // R-type instructions
            switch (decoded.funct3) {
                case 0x0: // ADD or SUB
                    if (decoded.funct7 == 0x00) { // ADD
                        reg[decoded.rd] = alu(reg[decoded.rs1], reg[decoded.rs2], OP_ADD);
                    } else if (decoded.funct7 == 0x20) { // SUB
                        reg[decoded.rd] = alu(reg[decoded.rs1], reg[decoded.rs2], OP_SUB);
                    }
                    break;
                case 0x1: // SLL
                    reg[decoded.rd] = alu(reg[decoded.rs1], reg[decoded.rs2], OP_SLL);
                    break;
                case 0x2: // SLT
                    reg[decoded.rd] = alu(reg[decoded.rs1], reg[decoded.rs2], OP_SLT);
                    break;
                case 0x3: // SLTU
                    reg[decoded.rd] = alu(reg[decoded.rs1], reg[decoded.rs2], OP_SLTU);
                    break;
                case 0x4: // XOR
                    reg[decoded.rd] = alu(reg[decoded.rs1], reg[decoded.rs2], OP_XOR);
                    break;
                case 0x5: // SRL or SRA
                    if (decoded.funct7 == 0x00) { // SRL
                        reg[decoded.rd] = alu(reg[decoded.rs1], reg[decoded.rs2], OP_SRL);
                    } else if (decoded.funct7 == 0x20) { // SRA
                        reg[decoded.rd] = alu(reg[decoded.rs1], reg[decoded.rs2], OP_SRA);
                    }
                    break;
                case 0x6: // OR
                    reg[decoded.rd] = alu(reg[decoded.rs1], reg[decoded.rs2], OP_OR);
                    break;
                case 0x7: // AND
                    reg[decoded.rd] = alu(reg[decoded.rs1], reg[decoded.rs2], OP_AND);
                    break;
            }
            break;
        case 0x03: // Load instructions (I-type)
            switch (decoded.funct3) {
                case 0x0: // LB
                    reg[decoded.rd] = memory_load(reg[decoded.rs1] + decoded.imm, BYTE);
                    break;
                case 0x1: // LH
                    reg[decoded.rd] = memory_load(reg[decoded.rs1] + decoded.imm, HALFWORD);
                    break;
                case 0x2: // LW
                    reg[decoded.rd] = memory_load(reg[decoded.rs1] + decoded.imm, WORD);
                    break;
                case 0x4: // LBU
                    reg[decoded.rd] = memory_load(reg[decoded.rs1] + decoded.imm, BYTE);
                    break;
                case 0x5: // LHU
                    reg[decoded.rd] = memory_load(reg[decoded.rs1] + decoded.imm, HALFWORD);
                    break;
            }
            break;
        case 0x23: // Store instructions (S-type)
            switch (decoded.funct3) {
                case 0x0: // SB
                    memory_store(reg[decoded.rs1] + decoded.imm, reg[decoded.rs2], BYTE);
                    break;
                case 0x1: // SH
                    memory_store(reg[decoded.rs1] + decoded.imm, reg[decoded.rs2], HALFWORD);
                    break;
                case 0x2: // SW
                    memory_store(reg[decoded.rs1] + decoded.imm, reg[decoded.rs2], WORD);
                    break;
            }
            break;
        case 0x63: // Branch instructions (B-type)
            switch (decoded.funct3) {
                case 0x0: // BEQ
                    if (alu(reg[decoded.rs1], reg[decoded.rs2], OP_BEQ)) {
                        pc = pc + decoded.imm;
                    }
                    break;
                case 0x1: // BNE
                    if (alu(reg[decoded.rs1], reg[decoded.rs2], OP_BNE)) {
                        pc = pc + decoded.imm;
                    }
                    break;
                case 0x4: // BLT
                    if (alu(reg[decoded.rs1], reg[decoded.rs2], OP_BLT)) {
                        pc = pc + decoded.imm;
                    }
                    break;
                case 0x5: // BGE
                    if (alu(reg[decoded.rs1], reg[decoded.rs2], OP_BGE)) {
                        pc = pc + decoded.imm;
                    }
                    break;
                case 0x6: // BLTU
                    if (alu(reg[decoded.rs1], reg[decoded.rs2], OP_BLTU)) {
                        pc = pc + decoded.imm;
                    }
                    break;
                case 0x7: // BGEU
                    if (alu(reg[decoded.rs1], reg[decoded.rs2], OP_BGEU)) {
                        pc = pc + decoded.imm;
                    }
                    break;
            }
            break;
        case 0x37: // LUI (U-type)
            reg[decoded.rd] = alu(0, decoded.imm, OP_LUI);
            break;
        case 0x17: // AUIPC (U-type)
            reg[decoded.rd] = alu(pc, decoded.imm, OP_AUIPC);
            break;
        case 0x6F: // JAL (J-type)
            reg[decoded.rd] = pc + 4;
            pc = pc + decoded.imm;
            break;
        case 0x67: // JALR (I-type)
            reg[decoded.rd] = pc + 4;
            pc = (reg[decoded.rs1] + decoded.imm) & ~1;
            break;
        default:
            // Handle unknown opcode
            break;
    }
}
