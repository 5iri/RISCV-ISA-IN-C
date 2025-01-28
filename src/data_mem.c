#include "riscv.h"


uint32_t memory[MEM_SIZE]; // Initialize memory to 0


int32_t memory_load(uint32_t addr, Operation operation){
    //to do memory loading for load word and load half and load byte

    if (addr >= MEM_SIZE) {
        // Handle invalid memory access
        return 0; // Could also raise an exception/error
    }

    switch (operation) {
    case BYTE: // LB: Load Byte (signed)
        return (int8_t)memory[addr];
    case HALFWORD: // LH: Load Halfword (signed)
        if (addr + 1 >= MEM_SIZE) return 0; // Check bounds
        return (int16_t)(memory[addr] | (memory[addr + 1] << 8));
    case WORD: // LW: Load Word (signed)
        if (addr + 3 >= MEM_SIZE) return 0; // Check bounds
        return (int32_t)(memory[addr] | (memory[addr + 1] << 8) | 
                            (memory[addr + 2] << 16) | (memory[addr + 3] << 24));
    case SIGNED_BYTE: // LBU: Load Byte (unsigned)
        return (uint8_t)memory[addr];
    case SIGNED_HALFWORD: // LHU: Load Halfword (unsigned)
        if (addr + 1 >= MEM_SIZE) return 0; // Check bounds
        return (uint16_t)(memory[addr] | (memory[addr + 1] << 8));
    default:
        return 0; // Unsupported load
    }
};
void memory_store(uint32_t addr, int32_t data, Operation operation){
    //to do memory storing for store word, store half, and store byte

    if (addr >= MEM_SIZE) {
        // Handle invalid memory access
        return; // Could also raise an exception/error
    }

        switch (operation) {
        case BYTE: // SB: Store Byte
            memory[addr] = (uint8_t)data;
            break;
        case HALFWORD: // SH: Store Halfword
            if (addr + 1 >= MEM_SIZE) return; // Check bounds
            memory[addr] = (uint8_t)data;
            memory[addr + 1] = (uint8_t)(data >> 8);
            break;
        case WORD: // SW: Store Word
            if (addr + 3 >= MEM_SIZE) return; // Check bounds
            memory[addr] = (uint8_t)data;
            memory[addr + 1] = (uint8_t)(data >> 8);
            memory[addr + 2] = (uint8_t)(data >> 16);
            memory[addr + 3] = (uint8_t)(data >> 24);
            break;
        default:
            return; // Unsupported store
    }
};

