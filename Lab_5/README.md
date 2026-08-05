# Lab 5: If-Else Statement Parser

This lab contains a Flex lexer and Bison parser for a simple if-else statement grammar.

## Files

- `ifelse.l` — Flex lexer specification
- `ifelse.y` — Bison parser specification

## Build Instructions

Open a terminal in `Lab_5` and run:

```sh
bison -d ifelse.y
flex ifelse.l
gcc ifelse.tab.c lex.yy.c -o ifelsechecker
```

## Run

```sh
./ifelsechecker
```

Enter one statement per line, for example:

```sh
if (a>b) x=y;
if (a>b) x=y; else x=z;
```

Example output:

```text
valid
valid
```

Press `Ctrl+C` or `Ctrl+Z` on Windows to exit.
