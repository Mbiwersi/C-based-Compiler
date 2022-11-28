
# Compiler

Custom built compiler using Yacc and Lex.

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
