#ifndef RISC_V_H
#define RISC_V_H

#include <stdio.h>
#include <stdint.h>

#define MEM_SIZE 1024
#define REG_COUNT 32

// Decoded instruction structure
typedef struct {
    uint32_t opcode;
    uint32_t rd;
    uint32_t funct3;
    uint32_t rs1;
    uint32_t rs2;
    uint32_t funct7;
    int32_t imm;
} DecodedInstruction;

// Operation type
typedef enum {
    OP_ADD,
    OP_ADDI,
    OP_UNKNOWN
} Operation;

// Memory and registers
extern uint32_t memory[MEM_SIZE];
extern int32_t reg[REG_COUNT];

// Program counter
extern uint32_t pc;

// Function prototypes
uint32_t fetch();
DecodedInstruction decode(uint32_t instr);
Operation get_operation(DecodedInstruction decoded);
int32_t alu(int32_t rs1, int32_t rs2, Operation operation); // ALU declaration
void memory_access();
void writeback();

#endif // RISC_V_H
