#ifndef RISC_V_H
#define RISC_V_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MEM_SIZE 1024
#define REG_COUNT 32

// Operation type
typedef enum {
    OP_ADD,
    OP_ADDI,
    OP_UNKNOWN
} Operation;



// Common fields for all instruction types
typedef struct {
    uint8_t opcode;
    uint8_t rd;
    uint8_t funct3;
    uint8_t rs1;
    uint8_t rs2;
    uint8_t funct7;
    int32_t imm;
} DecodedInstruction;

// I-type instruction structure
typedef struct {
    uint8_t opcode;
    uint8_t rd;
    uint8_t funct3;
    uint8_t rs1;
    int32_t imm;
} ITypeInstruction;

// R-type instruction structure
typedef struct {
    uint8_t opcode;
    uint8_t rd;
    uint8_t funct3;
    uint8_t rs1;
    uint8_t rs2;
    uint8_t funct7;
} RTypeInstruction;

// S-type instruction structure
typedef struct {
    uint8_t opcode;
    uint8_t funct3;
    uint8_t rs1;
    uint8_t rs2;
    int32_t imm;
} STypeInstruction;

// U-type instruction structure
typedef struct {
    uint8_t opcode;
    uint8_t rd;
    int32_t imm;
} UTypeInstruction;

// J-type instruction structure
typedef struct {
    uint8_t opcode;
    uint8_t rd;
    int32_t imm;
} JTypeInstruction;


// Memory and registers
extern uint32_t memory[MEM_SIZE];
extern int32_t reg[REG_COUNT];

// Program counter
extern uint32_t pc;

// Function prototypes
uint32_t fetch();
DecodedInstruction decode(uint32_t instr);
void get_operation(DecodedInstruction decoded);
int32_t alu(int32_t rs1, int32_t rs2, Operation operation); // ALU declaration
void memory_access();
void writeback();

#endif // RISC_V_H
