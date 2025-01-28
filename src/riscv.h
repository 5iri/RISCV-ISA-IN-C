#ifndef RISC_V_H
#define RISC_V_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define INSTR_MEM_SIZE 512
#define MEM_SIZE 512
#define REG_COUNT 32

// Operation type
typedef enum {
    OP_ADD,
    OP_ADDI,
    OP_SUB,
    OP_SLL,
    OP_SLLI,
    OP_SLT,
    OP_SLTI,
    OP_SLTU,
    OP_SLTIU,
    OP_XOR,
    OP_XORI,
    OP_OR,
    OP_ORI,
    OP_AND,
    OP_ANDI,
    OP_SRL,
    OP_SRLI,
    OP_SRA,
    OP_SRAI,
    OP_LUI,
    OP_AUIPC,
    OP_BEQ,
    OP_BNE,
    OP_BLT,
    OP_BGE,
    OP_BLTU,
    OP_BGEU,
    BYTE,
    HALFWORD,
    WORD,
    SIGNED_BYTE,
    SIGNED_HALFWORD,
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
extern uint32_t instr_memory[MEM_SIZE];
extern uint32_t memory[MEM_SIZE];
extern int32_t reg[REG_COUNT];

// Program counter
extern uint32_t pc;

// Function prototypes
uint32_t fetch();
DecodedInstruction decode(uint32_t instr);
void get_operation(DecodedInstruction decoded);
int32_t alu(int32_t rs1, int32_t rs2, Operation operation); // ALU declaration
void instr_dump();
void writeback();
void memory_store(uint32_t addr, int32_t data, Operation operation);
int32_t memory_load(uint32_t addr, Operation operation);

#endif // RISC_V_H
