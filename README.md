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

## Lexer doc
Character Classification: It reads the plain text of your .ccirc files character by character and groups them into discrete, meaningful symbols (such as TYPE_TOKEN, NUMBER_TOKEN, or PLUS_TOKEN), much like grouping letters into words in a natural language.

Automata Construction: Under the hood, the DeSiGNAR library parses your regular expressions and builds Nondeterministic Finite Automata (NFAs) using Thompson's construction, which are then converted into highly efficient Deterministic Finite Automata (DFAs) via the subset construction algorithm.

Maximal Munch Rule: When analyzing the text, the lexer simulates all these DFAs in parallel using the "longest match" principle. It always selects the pattern that consumes the most consecutive characters. If a tie occurs (e.g., the string source matching both TYPE_TOKEN and IDENTIFIER_TOKEN equally well), the tie is broken in favor of whichever token type was registered first in your C++ code.

Token Stream Purification: Before passing the data to the LL(1) parser, it filters out ignored character classes like whitespace and comments, ensuring the parser only receives syntactically significant tokens.

## Authors

- Ramon Belandria
- Frank Zerpa