%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SymTab.h"
#include "IOMngr.h"
#include "Semantics.h"
#include "CodeGen.h"

extern int yylex();	/* The next token function. */
extern char *yytext;   /* The matched token text.  */
extern int yyleng;      /* The token text length.   */
extern int yyparse();
void dumpTable();

extern SymTab *table;


%}


%union {
  long val;
  char * string;
  struct ExprRes * ExprRes;
  struct InstrSeq * InstrSeq;
}

%type <string> Id
%type <ExprRes> Factor
%type <ExprRes> Term
%type <ExprRes> Term2
%type <ExprRes> Expr
%type <InstrSeq> StmtSeq
%type <InstrSeq> Stmt
%type <ExprRes> BExpr

%token Ident 		
%token IntLit 	
%token Int
%token BoolLit
%token Bool
%token Write
%token IF
%token EQ 
%token LT
%token LTE
%token GT
%token GTE

%%

Prog			    :	Declarations StmtSeq {Finish($2);};
Declarations	:	Dec Declarations { };
              |	{ };
Dec			      :	Int Id ';' {enterName(table, $2);};
              | Bool Id ';' {enterName(table, $2);};
StmtSeq 		  :	Stmt StmtSeq {$$ = AppendSeq($1, $2);};
              |	{$$ = NULL;} ;
Stmt			    :	Write Expr ';' {$$ = doPrint($2);};
              |	Id '=' BExpr ';'	{$$ = doAssign($1, $3);};
              |	IF '(' BExpr ')' '{' StmtSeq '}' {$$ = doIf($3, $6);};
BExpr		      :	Expr EQ Expr {$$ = doEq($1, $3);};
              | Expr LT Expr {$$ = doLT($1, $3);};
              | Expr LTE Expr {$$ = doLTE($1, $3);};
              | Expr GT Expr {$$ = doGT($1, $3);};
              | Expr GTE Expr {$$ = doGTE($1, $3);};
              | Expr {$$ = $1;};
Expr			    :	Expr '+' Term {$$ = doAdd($1, $3); };
              | Expr '-' Term {$$ = doSub($1, $3);};
              |	Term {$$ = $1; };
Term		      :	Term '*' Term2	{$$ = doMult($1, $3);};
              | Term '/' Term2 {$$ = doDiv($1, $3);};
              | Term '%' Term2 {$$ = doMod($1, $3);};
              |	Term2 { $$ = $1; } ;
Term2         : '-' Term2 {$$ = doUnaryMin($2);};
              | Factor '^' Term2 {$$ = doExponent($1, $3);};
              | Factor {$$ = $1;};
Factor		    :	IntLit {$$ = doIntLit(yytext);};
              | BoolLit {$$ = doBoolLit(yytext);};
              |	Id { $$ = doRval($1); };
Id			      : Ident { $$ = strdup(yytext);}
 
%%

int yyerror(char *s)  {
  writeIndicator(getCurrentColumnNum());
  writeMessage("Illegal Character in YACC");
}
