# 📘 Lab 6: FIRST and FOLLOW Set Generator

This project computes the **FIRST** and **FOLLOW** sets for the following expression grammar used in **Compiler Design**.

## Grammar

```text
E  → T E'
E' → + T E' | ε
T  → F T'
T' → * F T' | ε
F  → ( E ) | id
```

## Features

- Computes FIRST sets
- Computes FOLLOW sets
- Supports epsilon (ε) productions
- Simple and beginner-friendly implementation
- Useful for LL(1) parser preparation

## Build

```bash
g++ -std=c++17 -o lab_6.exe .\lab_6\lab_6.cpp
```

## Run

```bash
lab_6.exe
```

## Sample Output

```text
------ FIRST SETS ------
FIRST(E)  = { (, id }
FIRST(E') = { +, ε }
FIRST(T)  = { (, id }
FIRST(T') = { *, ε }
FIRST(F)  = { (, id }

------ FOLLOW SETS ------
FOLLOW(E)  = { $, ) }
FOLLOW(E') = { $, ) }
FOLLOW(T)  = { +, $, ) }
FOLLOW(T') = { +, $, ) }
FOLLOW(F)  = { *, +, $, ) }
```

## Conclusion

This program demonstrates the computation of **FIRST** and **FOLLOW** sets using an iterative algorithm. It provides a practical understanding of grammar analysis and serves as a foundation for building **LL(1) parsers** in Compiler Design.

## Author

Author: [subhash107k](https://github.com/subhash107k)
