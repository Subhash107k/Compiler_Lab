# Compiler_Lab
A collection of Compiler Design and System Programming lab experiments using C, Lex/Flex, GCC preprocessing, and assembly generation

## Lab 2: Lexical Analyzer for Token Recognition using Flex

Source file: [Lab_2/tokenizer.l](Lab_2/tokenizer.l)

Build on Windows with WinFlexBison and GCC:

```powershell
Set-Location .\Lab_2
win_flex -o tokenizer.c tokenizer.l
gcc tokenizer.c -o tokenizer.exe
```

Run the lexer and type or paste a C-like snippet, then end input with `Ctrl+Z` and `Enter`:

```powershell
.\tokenizer.exe
```

## Lab 1: Basic C Programs

Source files:

- [Lab_1/sum_program.c](Lab_1/sum_program.c)
- [Lab_1/circle_area.c](Lab_1/circle_area.c)

Build with GCC:

```powershell
Set-Location .\Lab_1
gcc sum_program.c -o sum_program.exe
gcc circle_area.c -o circle_area.exe
```

Run the programs:

```powershell
.\sum_program.exe
.\circle_area.exe
```
