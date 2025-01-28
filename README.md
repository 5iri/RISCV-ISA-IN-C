# RISC-V ISA Implementation in C

This repository contains a C-based implementation of a RISC-V (Reduced Instruction Set Computer - Five) instruction set architecture (ISA). The project aims to provide a simple, educational, and functional implementation of the RISC-V ISA, which can be used for learning, experimentation, and development.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Building the Project](#building-the-project)
  - [Running the Emulator](#running-the-emulator)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## Introduction

RISC-V is an open-source instruction set architecture (ISA) that is gaining popularity due to its simplicity, modularity, and extensibility. This project provides a C-based implementation of a RISC-V emulator, which can execute RISC-V instructions. The emulator is designed to be easy to understand and modify, making it a great resource for students, hobbyists, and developers interested in computer architecture.

## Features

- **RISC-V Base Integer Instruction Set (RV32I)**: Supports the base integer instruction set, including arithmetic, logical, control flow, and memory operations.
- **Simple and Modular Design**: The code is structured to be easy to read and extend, making it suitable for educational purposes.
- **Cross-Platform**: Written in C, the emulator can be compiled and run on various platforms, including Linux, macOS, and Windows.
- **Debugging Support**: Basic debugging features are included to help users understand the execution flow and state of the emulator.

## Getting Started

### Prerequisites

To build and run this project, you will need:

- A C compiler (e.g., `gcc`, `clang`)
- `make` (for building the project)
- Git (for cloning the repository)

### Building the Project

1. Clone the repository:
   ```bash
   git clone https://github.com/5iri/RISCV-ISA-IN-C.git
   cd RISCV-ISA-IN-C
   ```

2. Build the project using `make`:
    ```bash
    make
    ```

This will compile the C source files and generate an executable named `riscv_core`.

## Running the Emulator

To run the emulator, simply execute the generated binary:

```bash
./riscv_core
```

## Project Structure

- The project is organized as follows:

    - `src/`: Contains the C source files for the emulator.

        - `main.c`: The entry point of the emulator.

        - `riscv.h`: Header Implementation of the RISC-V ISA.

        - `instr_mem.c`: Instr Memory management.

        - `data_mem.c`: Data Memory Management.
        
        - `decoder.c`: Decoding the instr.

        - `fetch.c`: fetches instructions from instr_mem.c.

        - `regfile.c`: register file which has all the registers.

        - `alu.c`: does all alu stuff.

        - `control_unit.c`: controls the flow of data in it.

- `Makefile`: The build configuration file.

- `README.md`: This file, providing an overview of the project.

- `example.hex`: a sample binary file which has the hex values of the instr running fibonacci sequence.