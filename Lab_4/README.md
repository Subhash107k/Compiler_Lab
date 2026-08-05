# Lab 4: Arithmetic Expression Evaluator Using Flex and Bison

This lab parses and evaluates integer arithmetic expressions using Flex and Bison.

## Files

- `key.l` — Flex lexical analyzer
- `y.y` — Bison parser

## Features

- Supports addition, subtraction, multiplication, and division
- Supports parentheses and integer expressions
- Respects operator precedence and associativity
- Handles division-by-zero
- Reports syntax errors

## Build Instructions

Open a terminal in `Lab_4` and run:

```powershell
win_bison -d y.y
win_flex key.l
gcc y.tab.c lex.yy.c -o evaluator.exe
```

## Run

```powershell
.\evaluator.exe
```

Example input:

```text
3+4*2
(3+4)*2
10/5+7
```

Example output:

```text
Result = 11
Result = 14
Result = 9
```

Press `Ctrl+Z` to exit on Windows.
