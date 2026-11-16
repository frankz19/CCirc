# CCirc Compiler

CCirc is a Domain-Specific Language (DSL) compiler for describing and simulating electrical circuits (source-resistor, RC, RL, and RLC circuits). This stage implements the lexical analyzer (`Lexer`) and the predictive $LL(1)$ syntax analyzer (`LLParser`) using C++17 and the DeSiGNAR library, along with an expression syntax tree printer.

## Project Structure

```text
ccirc-compiler/
├── .gitignore
├── CMakeLists.txt
├── README.md
├── include/
│   ├── ccirc_lexer.hpp
│   ├── ccirc_parser.hpp
│   └── tree_printer.hpp
├── src/
│   ├── ccirc_lexer.cpp
│   ├── ccirc_parser.cpp
│   ├── tree_printer.cpp
│   └── main.cpp
└── examples/
    └── rc_circuit.ccirc
```

## Requirements

- C++17 compatible compiler (GCC >= 9, Clang >= 14, or MSVC 2019+)
- CMake >= 3.20
- DeSiGNAR library

## Build

```bash
mkdir -p build && cd build
cmake -DDESIGNAR_INCLUDE_DIR=/path/to/Designar/include ..
cmake --build . --parallel
```

## Usage

Run the compiler with the default built-in example:

```bash
./ccirc
```

Run the compiler with a `.ccirc` source file:

```bash
./ccirc ../examples/rc_circuit.ccirc
```

## Authors

- Ramon Belandria
- Frank Zerpa