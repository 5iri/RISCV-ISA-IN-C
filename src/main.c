#include "riscv.h"

uint32_t memory[MEM_SIZE] = {0}; // Initialize memory to 0
uint32_t pc = 0; // Program counter starts at 0

int main() {
    // Initialize memory with some instructions
    memory[0] = 0x00100093; // ADDI x1, x0, 1  (x1 = 1)
    memory[1] = 0x00208133; // ADD x2, x1, x2  (x2 = x1 + x2)

    // Simulate the CPU
    while (pc < MEM_SIZE * 4) {
        uint32_t instr = fetch(); // Fetch instruction
        DecodedInstruction decoded = decode(instr);            // Decoding the fetched instruction
        get_operation(decoded);
        if (decoded.opcode == 0x13) {
            reg[decoded.rd] = alu( decoded.rs1, decoded.imm, get_operation(decoded));
        }
        else if (decoded.opcode == 0x33) {
            reg[decoded.rd] = alu(decoded.rs1, decoded.rs2, get_operation(decoded));
        }
        memory_access();          // Memory access (if needed)
        writeback();              // Writeback (if needed)
        pc += 4;                  // Increment program counter
    }

    printf("registers\n");
    for (int i = 0; i < 31; i++) {
        printf("x%d = %d\n", i, reg[i]);
    }
    return 0;
}