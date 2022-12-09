
# Compiler

Custom built compiler using Yacc and Lex.

## What is included
#### Interger Variables and Expressions
- Interger Literals, Variables
- Assignment Statements
- Arithemtic Operators (+, -, *, /, ^, -(unary minus))
#### Boolean Variables and Expressions

- Boolean Literals, Variables
- Assignment Statements
- Relational Operators (<, <=, ==, >=, >, !=)
- Boolean Operators (!, &&, ||)

#### Input / output
- read(comma delimted list of variables)
    - read(x, y, z)
    - 1 (true), and 0 (false) can be input for boolean variables
- print(comma delimted list of Expressions);
    - print(2*x, x^3(z*w), abc/xyz, c)
- printlines(expression)
    - print expression number of newlines
- printString("Literal String")

#### Control Structures
- if statements including optional else
- while loops

#### Arrays
- 1 Dimensional Arrays
- 2 Dimensional Arrays

#### Functions
- void parameterless functions

## Run Locally (GNU / MAC)

Clone the project

```bash
git clone https://github.com/Mbiwersi/Final-Project
```

Go to the project directory

```bash
cd my-project
```

Generate supporting yacc files

```bash
yacc -d ExprEval.y
```

Generate supporting lex files

```bash
lex lex1.l
```

Compile Files

```bash
cc -o comp lex.yy.c y.tab.c SymTab.c Semantics.c CodeGen.c IOMngr.c main.c
```

Execute the Program

```bash
./comp source.txt listing.lst asmCode.asm
```

## Run Locally (Windows / GCC)

Clone the project

```bash
git clone https://github.com/Mbiwersi/Final-Project
```

Go to the project directory

```bash
cd my-project
```

Generate supporting yacc files

```bash
bison -dy ExprEval.y
```

Generate supporting lex files

```bash
lex lex1.l
```

Compile Files

```bash
gcc -o comp lex.yy.c y.tab.c SymTab.c Semantics.c CodeGen.c IOMngr.c main.c
```

Execute the Program

```bash
./comp source.txt listing.lst asmCode.asm
```
