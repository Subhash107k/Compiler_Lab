# Compiler Lab

A collection of Compiler Design laboratory experiments implemented using **C Programming** and **Flex (Lexical Analyzer Generator)**. Each lab demonstrates fundamental concepts of compiler construction, lexical analysis, and token processing.

## Repository Structure

### Lab 1 – Basic C Programs

Introduction to C programming concepts through simple arithmetic applications.

**Programs:**

* `sum_program.c` – Calculates the sum of two numbers
* `circle_area.c` – Calculates the area of a circle

**Topics Covered:**

* Variables and data types
* User input and output
* Arithmetic operations
* Basic program structure

---

### Lab 2 – Lexical Analyzer Using Flex

A simple lexical analyzer that scans source code and identifies various token types.

**Files:**

* `tokenizer.l`

**Recognized Tokens:**

* Keywords
* Identifiers
* Numbers
* Operators
* Separators

**Topics Covered:**

* Lexical analysis
* Token recognition
* Flex programming
* Source code scanning

---

### Lab 3 – Token Counter Using Flex

A lexer and token counter implementation that demonstrates token generation and counting.

**Files:**

* `token_counter.l`
* `lex.yy.c`
* `token_counter.c`

**Features:**

* Token generation using Flex
* Token counting and classification
* Source code analysis

**Topics Covered:**

* Lexer generation
* Token processing
* Compiler front-end concepts

---

## Requirements

* GCC Compiler (MinGW/MSYS2 or equivalent)
* Flex / WinFlexBison
* Windows PowerShell, Command Prompt, or Linux Terminal

## Quick Build Guide

### Lab 1

```powershell
cd Lab_1

gcc sum_program.c -o sum_program.exe
gcc circle_area.c -o circle_area.exe
```

### Lab 2

```powershell
cd Lab_2

win_flex -o tokenizer.c tokenizer.l
gcc tokenizer.c -o tokenizer.exe
```

### Lab 3

```powershell
cd Lab_3

flex token_counter.l
gcc lex.yy.c -o lexer.exe
gcc token_counter.c -o token_counter.exe
```

## Running Programs

### Lab 1

```powershell
.\sum_program.exe
.\circle_area.exe
```

### Lab 2

```powershell
.\tokenizer.exe
```

Enter a C-like code snippet and press **Ctrl + Z** followed by **Enter** to finish input.

### Lab 3

```powershell
type sample_input.txt | lexer.exe | token_counter.exe
```

## Learning Outcomes

After completing these experiments, students will be able to:

* Understand the structure of C programs
* Perform basic compilation using GCC
* Implement lexical analyzers using Flex
* Recognize and classify programming language tokens
* Generate lexers automatically
* Analyze source code through tokenization
* Understand fundamental compiler design concepts

## Author

Compiler Design Laboratory

Department of Computer Science & Engineering
