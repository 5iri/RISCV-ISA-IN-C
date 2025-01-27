#include "riscv.h"
#include <string.h>


uint32_t memory[MEM_SIZE]; // Initialize memory to 0


// Function to load instructions from a hex file into memory
int load_program(const char *filename) {
    FILE *file = fopen(filename, "r");  // Open the file in text read mode
    if (!file) {
        perror("Failed to open file");
        return -1;
    }

    char line[256];
    int count = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove newline character if present
        line[strcspn(line, "\n")] = '\0';

        // Parse the line into 32-bit hexadecimal integers
        int len = strlen(line);
        for (int i = 0; i < len; i += 10) { // Process 8 hex characters (4 bytes) at a time
            // Extract 8 characters (4 bytes) at a time
            char byte_str[11] = {0}; // 8 characters + null terminator
            strncpy(byte_str, &line[i], 10); // Copy 8 characters

            // Convert the 8-character hex string to a 32-bit integer
            uint32_t value = (uint32_t)strtoul(byte_str, NULL, 16);

            // Print the value in the format 0x001041b3
            memory[count] = value;
            count++;
        }
    }

    fclose(file);
    return 0;  // Success
}

void memory_access() {
    const char *filename = "src/example.hex";  // Hex file containing only hex values
    load_program(filename);
}
