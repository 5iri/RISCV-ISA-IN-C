#include "riscv.h"

uint32_t pc = 0; // Program counter starts at 0

int main() {
    // Simulate the CPU
    memory_access();
    while (pc < MEM_SIZE * 4) {
        uint32_t instr = fetch(); // Fetch instruction
        DecodedInstruction decoded = decode(instr);            // Decoding the fetched instruction
        get_operation(decoded);
        if (decoded.opcode == 0x13) {
            reg[decoded.rd] = alu( reg[decoded.rs1], decoded.imm, get_operation(decoded));
        }
        else if (decoded.opcode == 0x33) {
            reg[decoded.rd] = alu(reg[decoded.rs1], reg[decoded.rs2], get_operation(decoded));
        }
        writeback();              // Writeback (if needed)
        pc += 4;                  // Increment program counter
    }

    printf("registers\n");
    for (int i = 0; i < 31; i++) {
        printf("x%d = %d\n", i, reg[i]);
    }
    
    return 0;
}