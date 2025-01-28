#include "riscv.h"

uint32_t pc = 0; // Program counter starts at 0

int main() {
    // Simulate the CPU
    instr_dump();
    while (pc < MEM_SIZE * 4) {
        uint32_t instr = fetch(); // Fetch instruction
        DecodedInstruction decoded = decode(instr);            // Decoding the fetched instruction
        get_operation(decoded);
        writeback();              // Writeback (if needed)
        pc += 4;                  // Increment program counter
    }

    printf("registers\n");
    for (int i = 0; i < 31; i++) {
        printf("x%d = %d\n", i, reg[i]);
    }

    printf("memory\n");
    for (int i = 0; i < MEM_SIZE; i++) {
        printf("memory_loc[%d] = %d\n", i, memory[i]);
    }
    
    return 0;
}