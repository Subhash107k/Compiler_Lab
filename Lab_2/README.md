# Lab 2: Lexical Analyzer for Token Recognition using Flex

This folder contains a Flex-based lexical analyzer that recognizes keywords, identifiers, numbers, operators, and separators.

Files:

- [tokenizer.l](tokenizer.l)

Build on Windows with WinFlexBison and GCC:

```powershell
win_flex -o tokenizer.c tokenizer.l
gcc tokenizer.c -o tokenizer.exe
```

Run the lexer and type or paste a C-like snippet, then end input with `Ctrl+Z` and `Enter`:

```powershell
.\tokenizer.exe
```