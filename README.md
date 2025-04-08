# Compiler Project – Stage 1  
**Lexical and Syntax Analysis for a Toy Programming Language**

---

## Overview

This project implements the first stage of a compiler front-end using **GCC version 11.4.0** on **Ubuntu 22.04 (via WSL)**. It includes the design and implementation of:

- A **lexical analyzer** to tokenize source code efficiently
- A **syntax analyzer** (predictive parser) that verifies the syntactic structure of input programs using a parse table
- A basic **comment remover** for pre-processing
- Support utilities including automated computation of **FIRST and FOLLOW** sets and **parse tree generation**

---

## Project Structure

### 📁 Files and Function Descriptions

---

### `lexer.c`

#### `FILE* getStream(FILE* fp)`
- Efficiently loads source code from the file `fp` using a **twin buffer** mechanism.
- Reduces I/O overhead by buffering a fixed-size block of code into memory.
- Maintains the file pointer for sequential access and future reads.

#### `tokenInfo getNextToken(twinBuffer B)`
- Reads the buffered character stream to **recognize and tokenize lexemes**.
- Returns relevant token information encapsulated in a `tokenInfo` struct.
- Detects and reports lexical errors with line numbers.

#### `void removeComments(char* testcaseFile, char* cleanFile)`
- Removes comments from the source file and writes the cleaned output to `cleanFile`.
- Used **once** via the driver to showcase functionality.
- Lexer **does not** rely on the cleaned file—comments are ignored during tokenization.

---

### `parser.c`

#### `FirstAndFollow ComputeFirstAndFollowSets(grammar G)`
- Computes the **FIRST and FOLLOW sets** for the provided grammar.
- Automates the process when possible. Manual entry is supported if required.

#### `void createParseTable(FirstAndFollow F, table T)`
- Builds a **predictive parse table** using computed FIRST and FOLLOW sets.

#### `parseTree parseInputSourceCode(char* testcaseFile, table T)`
- Parses the input file using top-down predictive parsing.
- Constructs and returns a **parse tree**.
- Displays:
  - Detailed **syntax errors** with line numbers.
  - Confirmation message:  
    `"Input source code is syntactically correct..........."` if no syntax errors are found.

#### `void printParseTree(parseTree PT, char* outfile)`
- Prints the parse tree **inorder** to `outfile` in the following format:

```
lexeme          CurrentNode lineno   tokenName     valueIfNumber  parentNodeSymbol  isLeafNode  NodeSymbol
--------        ------------ ------  ------------  -------------  ----------------  ----------  -----------
id              ---          2       ID            ---            <var>             yes         ID
----            ---          ---     ---           ---            ROOT              no          <program>
```

---

### Header and Support Files

- `lexerDef.h`: Data structures for `lexer.c`
- `lexer.h`: Function declarations for `lexer.c`
- `parserDef.h`: Data structures for grammar, parse tree, etc.
- `parser.h`: Function declarations for `parser.c`
- `driver.c`: Drives the flow of the compiler front-end

---

## 🔧 Compilation & Execution

Ensure you're using **GCC 11.4.0** under **Ubuntu 22.04 (WSL)**.

### Build the Project

```bash
make
```

### Run the Executable

```bash
./stage1exe testfile.txt output.txt
```

- `testfile.txt`: Input source code file
- `output.txt`: File where parse tree is printed

---

## ⚙️ Tools & Techniques Used

- Twin buffer for optimized lexical analysis
- Token data structure with detailed metadata
- FIRST and FOLLOW computation (auto/manual)
- Predictive parsing using a parsing table
- Inorder parse tree generation
- Modular code design following clean compiler architecture

---

## ✍️ Notes

- The `removeComments()` function is a utility only for demonstration; the lexer processes the original source file.
- This is **Stage 1** of a multi-stage compiler pipeline. Future enhancements may include semantic analysis, intermediate code generation, and optimization.

---

## 📁 Example Output

> After a successful syntax check:

```
Input source code is syntactically correct...........
```

> Output parse tree (partial):

```
read            ---          1       READ          ---            <ioStmt>          yes         READ
----            ---          ---     ---           ---            <stmt>            no          <ioStmt>
```

---

## 📌 Author & Credits

Developed as part of the Curiosity inside me.
