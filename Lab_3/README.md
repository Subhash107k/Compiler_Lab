# Lab 3 – Token Counter Using Flex

## Overview

This lab demonstrates lexical analysis and token counting using Flex. The lexer identifies tokens from the input source code, while the token counter counts and displays the number of tokens recognized.

## Files

- `token_counter.l` – Flex lexer rules
- `lex.yy.c` – Generated lexer source file
- `token_counter.c` – Token counting program

## Compilation

Generate the lexer:

```powershell
flex token_counter.l
```

Compile the programs:

```powershell
gcc lex.yy.c -o lexer.exe
gcc token_counter.c -o token_counter.exe
```

## Execution

Run the lexer and token counter:

```powershell
type sample_input.txt | lexer.exe | token_counter.exe
```

## Learning Outcomes

- Understand lexical analysis using Flex
- Generate lexer source code automatically
- Recognize and process tokens from input
- Count different token types in source code

## Author

Compiler Lab – Lab 3  
Token Counter Using Flex