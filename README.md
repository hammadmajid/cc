# Compiler Construction Course - Assignments

This repository contains assignments for a compiler construction course.

## Assignment 1 (a1) - Lexical Analysis with Flex

### Overview

The lexer tokenizes input according to the following patterns:

- **Numbers**: One or more digits (0-9)
- **Strings**: Text enclosed in double quotes
- **Comments**: Lines starting with `#`
- **Identifiers**: Variable names or commands
- **Separators**: Spaces, tabs, newlines, and commas (ignored)

### Running with Makefile

```bash
make
```
### Running without Makefile

#### Step 1: Generate C code from Flex definition

```bash
cd a1
flex lexer.l
```

This generates `lex.yy.c` from `lexer.l`.

#### Step 2: Compile the C code

```bash
gcc lex.yy.c -o lexer
```

This creates the `lexer` executable.

#### Step 3: Run the lexer

```bash
./lexer
```

The lexer will process `input_data.hammad` and output tokenized results.
