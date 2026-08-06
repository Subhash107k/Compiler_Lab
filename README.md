# 🖥️ Compiler Lab

> A comprehensive collection of **Compiler Design laboratory experiments** implemented using **C Programming**, **Flex**, and **Bison**. These labs cover compiler front-end concepts including lexical analysis, token recognition, parsing, syntax validation, and expression evaluation.

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Flex](https://img.shields.io/badge/Flex-Lexical%20Analyzer-green.svg)
![Bison](https://img.shields.io/badge/Bison-Parser-orange.svg)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-lightgrey.svg)
![License](https://img.shields.io/badge/License-MIT-success.svg)

---

# 📖 Overview

This repository is designed for students learning compiler design and practical compiler front-end implementation. It includes a sequence of incremental labs:

1. Basic C programming exercises.
2. Lexical analysis using Flex.
3. Token counting and reporting using Flex.
4. Arithmetic expression parsing and evaluation using Flex + Bison.
5. If-else statement parsing and syntax validation using Flex + Bison.
6. FIRST and FOLLOW set generation for an expression grammar.

Each lab contains source files, build instructions, and sample usage to help you understand the compiler construction workflow.

---

# 📂 Repository Structure

```text
Compiler_Lab/
│
├── Lab_1/
│   ├── circle_area.c
│   ├── sum_program.c
│   └── README.md
│
├── Lab_2/
│   ├── tokenizer.l
│   └── README.md
│
├── Lab_3/
│   ├── token_counter.l
│   ├── lex.yy.c
│   └── README.md
│
├── Lab_4/
│   ├── key.l
│   ├── y.y
│   └── README.md
│
├── Lab_5/
│   ├── ifelse.l
│   ├── ifelse.y
│   └── README.md
│
├── Lab_6/
│   ├── Lab_6.cpp
│   └── README.md
│
├── LICENSE
└── README.md
```

---

# ⚙️ Prerequisites

- GCC Compiler (MinGW / MSYS2)
- Flex or WinFlexBison
- Bison or WinFlexBison
- Windows PowerShell, Command Prompt, or Git Bash

## Verify installation

```powershell
gcc --version
flex --version
bison --version
```

---

# 🔧 Build Instructions

## Lab 1 — Basic C Programs

```powershell
cd Lab_1
gcc sum_program.c -o sum_program.exe
gcc circle_area.c -o circle_area.exe
```

## Lab 2 — Lexical Analyzer Using Flex

```powershell
cd Lab_2
win_flex -o tokenizer.c tokenizer.l
gcc tokenizer.c -o tokenizer.exe
```

## Lab 3 — Token Counter Using Flex

```powershell
cd Lab_3
flex token_counter.l
gcc lex.yy.c -o lexer.exe
```

## Lab 4 — Arithmetic Expression Evaluator (Flex + Bison)

```powershell
cd Lab_4
win_bison -d y.y
win_flex key.l
gcc y.tab.c lex.yy.c -o evaluator.exe
```

## Lab 5 — If-Else Parser Using Flex + Bison

```powershell
cd Lab_5
bison -d ifelse.y
flex ifelse.l
gcc ifelse.tab.c lex.yy.c -o ifelsechecker.exe
```

## Lab 6 — FIRST and FOLLOW Set Generator

```powershell
cd Lab_6
g++ -std=c++17 -o lab_6.exe Lab_6.cpp
```

---

# ▶️ Running the Labs

## Lab 1

```powershell
cd Lab_1
.\sum_program.exe
.\circle_area.exe
```

## Lab 2

```powershell
cd Lab_2
.\tokenizer.exe
```

Finish input with:

```text
Ctrl + Z
Enter
```

## Lab 3

```powershell
cd Lab_3
.\lexer.exe
```

Or use file input mode:

```powershell
.\lexer.exe < sample_input.txt
```

## Lab 4

```powershell
cd Lab_4
.\evaluator.exe
```

## Lab 5

```powershell
cd Lab_5
.\ifelsechecker.exe
```

## Lab 6

```powershell
cd Lab_6
.\lab_6.exe
```

---

# 🧪 Lab Details

## Lab 1 — Basic C Programs

### Files

- [Lab_1/sum_program.c](Lab_1/sum_program.c)
- [Lab_1/circle_area.c](Lab_1/circle_area.c)

### Description

Lab 1 contains two beginner C programs that demonstrate console input, arithmetic operations, and output formatting.

### Features

- Read integers from standard input
- Perform addition
- Calculate circle area using `π × r²`
- Display formatted output

### Sample Input and Output

**sum_program**

```text
Enter two numbers: 4 5
Sum = 9
```

**circle_area**

```text
Enter radius: 3
Area = 28.26
```

## Lab 2 — Lexical Analyzer Using Flex

### Files

- [Lab_2/tokenizer.l](Lab_2/tokenizer.l)

### Description

Lab 2 uses Flex to build a lexical analyzer that tokenizes C-style code. This lab focuses on pattern matching and token recognition.

### Supported Tokens

- Keywords: `int`, `float`, `if`, `else`, `return`
- Identifiers
- Numeric constants
- Operators
- Separators and delimiters

### Sample output

```text
Keyword: int
Identifier: main
Separator: (
Separator: )
Separator: {
Keyword: return
Number: 5
Separator: ;
Separator: }
```

## Lab 3 — Token Counter Using Flex

### Files

- [Lab_3/token_counter.l](Lab_3/token_counter.l)
- `Lab_3/lex.yy.c` _(generated automatically by Flex)_

### Description

Lab 3 extends lexical analysis by counting token categories and producing a summary report at the end.

### Token categories

- Keywords
- Identifiers
- Numbers
- Operators
- Delimiters
- Comments

### Sample output

```text
KEYWORD: int
IDENTIFIER: main
DELIMITER: (
DELIMITER: )
DELIMITER: {
KEYWORD: int
IDENTIFIER: x
OPERATOR: =
NUMBER: 10
DELIMITER: ;
KEYWORD: return
IDENTIFIER: x
DELIMITER: ;
DELIMITER: }

===== TOKEN SUMMARY =====
Keywords    : 3
Identifiers : 3
Numbers     : 1
Operators   : 1
Delimiters  : 6
Comments    : 0
Total       : 14
```

## Lab 4 — Arithmetic Expression Evaluator (Flex + Bison)

### Files

- [Lab_4/key.l](Lab_4/key.l)
- [Lab_4/y.y](Lab_4/y.y)

### Description

Lab 4 builds an expression parser with Flex and Bison. The parser evaluates integer arithmetic expressions while enforcing operator precedence and correct grouping.

### Supported expressions

- Addition: `+`
- Subtraction: `-`
- Multiplication: `*`
- Division: `/`
- Parentheses: `()`

### Example input

```text
3+4*2
(3+4)*2
10/5+7
```

### Example output

```text
Result = 11
Result = 14
Result = 9
```

### Error handling

- Detects invalid syntax
- Reports division by zero

## Lab 5 — If-Else Parser Using Flex + Bison

### Files

- [Lab_5/ifelse.l](Lab_5/ifelse.l)
- [Lab_5/ifelse.y](Lab_5/ifelse.y)

### Description

Lab 5 implements a parser that validates if and if-else statements and resolves the dangling-else ambiguity using grammar precedence.

### Supported syntax

- Simple `if` statements
- `if-else` statements
- Nested if-else structures
- Relational expressions
- Assignment statements

### Example input

```text
if (a>b) x=y;
if (a>b) x=y; else x=z;
```

### Example output

```text
valid
valid
```

## Lab 6 — FIRST and FOLLOW Set Generator

### Files

- [Lab_6/Lab_6.cpp](Lab_6/Lab_6.cpp)
- [Lab_6/README.md](Lab_6/README.md)

### Description

Lab 6 computes the FIRST and FOLLOW sets for an expression grammar. It demonstrates grammar analysis for LL(1) parser preparation.

### Sample output

```text
------ FIRST SETS ------
FIRST(E) = { (, id }
FIRST(E') = { +, e }
FIRST(T) = { (, id }
FIRST(T') = { *, e }
FIRST(F) = { (, id }

------ FOLLOW SETS ------
FOLLOW(E) = { $, ) }
FOLLOW(E') = { $, ) }
FOLLOW(T) = { +, $, ) }
FOLLOW(T') = { +, $, ) }
FOLLOW(F) = { *, +, $, ) }
```

### Quick Links

- [Open Lab 6 README](Lab_6/README.md)
- [Open Lab 6 source](Lab_6/Lab_6.cpp)

## Sample Inputs and Outputs

| Lab   | Sample Input                                              | Sample Output                                                                                                                                                                                                                                            |
| ----- | --------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Lab 1 | `4 5` for `sum_program.c`; `3` for `circle_area.c`        | `Sum = 9`; `Area = 28.26`                                                                                                                                                                                                                                |
| Lab 2 | `int main() { return 5; }`                                | `Keyword: int`, `Identifier: main`, `Separator: (`, `Separator: )`, `Separator: {`, `Keyword: return`, `Number: 5`, `Separator: ;`, `Separator: }`                                                                                                       |
| Lab 3 | `int main() { int x = 10; return x; }`                    | `KEYWORD: int`, `IDENTIFIER: main`, `DELIMITER: (`, `DELIMITER: )`, `DELIMITER: {`, `KEYWORD: int`, `IDENTIFIER: x`, `OPERATOR: =`, `NUMBER: 10`, `DELIMITER: ;`, `KEYWORD: return`, `IDENTIFIER: x`, `DELIMITER: ;`, `DELIMITER: }`, then token summary |
| Lab 4 | `3+4*2`, `(3+4)*2`, `10/5+7`                              | `Result = 11`, `Result = 14`, `Result = 9`                                                                                                                                                                                                               |
| Lab 5 | `if (a>b) x=y;` and `if (a>b) x=y; else x=z;`             | `valid`, `valid`                                                                                                                                                                                                                                         |
| Lab 6 | No runtime input; the grammar is hardcoded in `Lab_6.cpp` | FIRST/FOLLOW sets for `E`, `E'`, `T`, `T'`, and `F`                                                                                                                                                                                                      |

---

# 🎯 Why this repository matters

These labs provide hands-on experience with the compiler front-end pipeline:

- Lexical analysis using regular expressions
- Token generation and classification
- Parser construction with Bison grammars
- Semantic actions for expression evaluation
- Syntax validation and error reporting

The sequence from Lab 1 to Lab 6 gradually builds toward a working compiler-like front end.

---

# 🛠️ Technologies Used

| Technology            | Purpose                    |
| --------------------- | -------------------------- |
| C Programming         | Implementation language    |
| GCC                   | Compiler                   |
| Flex (Lex)            | Lexical analyzer generator |
| Bison (Yacc)          | Parser generator           |
| PowerShell / Git Bash | Build and execution shell  |

---

# 📄 License

This project is licensed under the **MIT License**.

See the [LICENSE](LICENSE) file for details.

---

# 👨‍💻 Author

**Subhash Thakur**

GitHub: [https://github.com/subhash107k](https://github.com/subhash107k)

---

⭐ If this repository helped you, consider giving it a **Star** on GitHub!
