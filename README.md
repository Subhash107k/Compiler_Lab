# Compiler Lab

A collection of Compiler Design laboratory experiments implemented using **C Programming** and **Flex (Lexical Analyzer Generator)**. These experiments demonstrate fundamental concepts of compiler construction, lexical analysis, token recognition, and source code processing.

---

## Repository Structure

### Lab 1 – Basic C Programs

Introduction to C programming through simple mathematical applications.

#### Programs

* `sum_program.c` – Calculates the sum of two numbers
* `circle_area.c` – Calculates the area of a circle

#### Topics Covered

* Variables and data types
* User input and output
* Arithmetic operations
* Basic program structure
* GCC compilation process

---

### Lab 2 – Lexical Analyzer Using Flex

A simple lexical analyzer that scans source code and identifies different categories of tokens.

#### Files

* `tokenizer.l`

#### Recognized Tokens

* Keywords
* Identifiers
* Numeric constants
* Operators
* Delimiters / Separators

#### Topics Covered

* Lexical analysis
* Token recognition
* Pattern matching using Flex
* Source code scanning
* Compiler front-end fundamentals

---

### Lab 3 – Token Counter Using Flex

A token analyzer that recognizes tokens from source code and generates a summary report of token counts.

#### Files

* `token_counter.l`
* `lex.yy.c` *(generated automatically by Flex)*

#### Features

* Keyword recognition
* Identifier detection
* Number recognition
* Operator detection
* Delimiter detection
* Comment recognition
* Token counting and classification
* Summary report generation

#### Sample Output

```text
KEYWORD: int
IDENTIFIER: x
OPERATOR: =
NUMBER: 5
DELIMITER: ;

===== TOKEN SUMMARY =====
Keywords    : 1
Identifiers : 1
Numbers     : 1
Operators   : 1
Delimiters  : 1
Comments    : 0
Total       : 5
```

#### Topics Covered

* Lexer generation using Flex
* Token classification
* Source code analysis
* Compiler front-end processing
* Token statistics and reporting

---

## Requirements

### Software

* GCC Compiler (MinGW/MSYS2)
* Flex / WinFlexBison
* Windows PowerShell, Command Prompt, Git Bash, or Linux Terminal

### Verify Installation

```powershell
gcc --version
flex --version
```

---

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

flex tokenizer.l
gcc lex.yy.c -o tokenizer.exe
```

### Lab 3

```powershell
cd Lab_3

flex token_counter.l
gcc lex.yy.c -o lexer.exe
```

---

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

Enter source code and finish input with:

```text
Ctrl + Z
Enter
```

---

### Lab 3

#### Interactive Mode

```powershell
.\lexer.exe
```

Example Input:

```c
int x = 5;
```

Finish input using:

```text
Ctrl + Z
Enter
```

#### File Input Mode

Create a file named `sample_input.txt`:

```c
int main()
{
    int x = 5;
    return x;
}
```

Run:

```powershell
.\lexer.exe < sample_input.txt
```

---

## Learning Outcomes

After completing these experiments, students will be able to:

* Understand the phases of a compiler
* Perform program compilation using GCC
* Create lexical analyzers using Flex
* Recognize and classify programming language tokens
* Generate lexers automatically from specifications
* Analyze source code through tokenization
* Understand compiler front-end processing
* Implement token counting and reporting systems

---

## Technologies Used

* C Programming Language
* Flex (Fast Lexical Analyzer Generator)
* GCC Compiler
* Windows PowerShell / Linux Terminal

---

## Author

**Compiler Design Laboratory**

Department of Computer Science & Engineering
...