# Lab 2 – Lexical Analyzer Using Flex

## Overview

This lab implements a simple lexical analyzer using Flex. The program scans input code and identifies different types of tokens such as keywords, identifiers, numbers, operators, and separators.

## Files

- `tokenizer.l` – Flex source file containing token recognition rules

## Compilation

Build the lexer using WinFlexBison and GCC:

```powershell
win_flex -o tokenizer.c tokenizer.l
gcc tokenizer.c -o tokenizer.exe
```

## Execution

Run the program:

```powershell
.\tokenizer.exe
```

Enter or paste a C-like code snippet and press **Ctrl + Z** followed by **Enter** to end the input.

## Learning Outcomes

- Understand lexical analysis
- Recognize common programming language tokens
- Generate a lexer using Flex
- Process source code input automatically

## Author

Compiler Lab – Lab 2  
Lexical Analyzer Using Flex