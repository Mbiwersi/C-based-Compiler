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
extern SymTab *stringTable;
extern SymTab *arrayTable;


%}


%union {
  long val;
  char * string;
  struct ExprRes * ExprRes;
  struct ExprResList * ExprResList;
  struct InstrSeq * InstrSeq;
  struct IdList * IdList;
}

%type <string> Id
%type <string> ArraySize
%type <IdList> IdentList
%type <ExprRes> Factor
%type <ExprRes> Term
%type <ExprRes> Term2
%type <ExprRes> Expr
%type <ExprResList> ExprList
%type <InstrSeq> StmtSeq
%type <InstrSeq> Stmt
%type <ExprRes> BExpr
%type <ExprRes> BExpr1
%type <ExprRes> BExpr2
%type <ExprRes> BExpr3


%token Ident
%token IntLit 	
%token Int
%token BoolLit
%token Bool
%token Read
%token Print
%token Printlines
%token Printspaces
%token PrintString
%token StringLit
%token IF
%token ELSE
%token WHILE
%token AND
%token OR
%token EQ 
%token NEQ
%token NOT
%token LT
%token LTE
%token GT
%token GTE
%token Void

%%

Prog			    :	Declarations StmtSeq                                  {Finish($2);};
Declarations	:	Dec Declarations                                      { };
              |	                                                      { };
Dec			      :	Int Id ';'                                            {enterInt($2);};
              | Bool Id ';'                                           {enterBool($2);};
              | Int Id '[' ArraySize ']' ';'                          {arrayDec($2, $4);};
              | Int Id '[' ArraySize ']' '[' ArraySize ']' ';'        {twoDArrayDec($2, $4, $7);};
              | Bool Id '[' ArraySize ']' ';'                         {arrayDec($2, $4);};
              | Bool Id '[' ArraySize ']' '[' ArraySize ']' ';'       {twoDArrayDec($2, $4, $7);};
              | Void Id '(' ')' '{' StmtSeq '}'                       {doFunctionDec($2, $6);};
StmtSeq 		  :	Stmt StmtSeq                                          {$$ = AppendSeq($1, $2);};
              |	                                                      {$$ = NULL;} ;
Stmt			    :	Print Expr ';'                                        {$$ = doPrint($2, "_nl");};
              | Print '(' ExprList ')' ';'                            {$$ = doPrintList($3);};
              | Read '(' IdentList ')' ';'                            {$$ = doRead($3);};
              | Printlines '(' Expr ')' ';'                           {$$ = doPrintLines($3);};
              | Printspaces '(' Expr ')' ';'                          {$$ = doPrintSpaces($3);};
              | PrintString '(' Expr  ')' ';'                         {$$ = doPrintString();};
              |	Id '=' BExpr ';'	                                    {$$ = doAssign($1, $3);};
              | Id '[' Expr ']' '=' BExpr ';'                         {$$ = doArrayAssign($1, $3, $6);};
              | Id '[' Expr ']' '[' Expr ']' '=' BExpr ';'            {$$ = do2DArrayAssign($1, $3, $6, $9);}
              |	IF '(' BExpr ')' '{' StmtSeq '}'                      {$$ = doIf($3, $6);};
              | IF '(' BExpr ')' '{' StmtSeq '}' ELSE '{' StmtSeq '}' {$$ = doIfElse($3, $6, $10);};
              | WHILE '(' BExpr ')' '{' StmtSeq '}'                   {$$ = doWhile($3, $6);};
              | Id '(' ')' ';'                                        {$$ = doFucntionCall($1);};
ExprList      : BExpr ',' ExprList                                    {$$ = appendExprNode($1, $3);};
              | BExpr                                                 {$$ = createExprNode($1);};
BExpr         : BExpr OR BExpr1                                       {$$ = doOr($1, $3);};
              | BExpr1                                                {$$ = $1;};
BExpr1        : BExpr1 AND BExpr2                                     {$$ = doAnd($1, $3);};
              | BExpr2                                                {$$ = $1;};
BExpr2		    : BExpr2 LT BExpr3                                      {$$ = doLT($1, $3);};
              | BExpr2 LTE BExpr3                                     {$$ = doLTE($1, $3);};
              | BExpr2 GT BExpr3                                      {$$ = doGT($1, $3);};
              | BExpr2 GTE BExpr3                                     {$$ = doGTE($1, $3);};
              | BExpr3                                                {$$ = $1;};
BExpr3        :	BExpr3 EQ Expr                                        {$$ = doEq($1, $3);};
              | BExpr3 NEQ Expr                                       {$$ = doNotEq($1, $3);};
              | Expr                                                  {$$ = $1;};
Expr			    :	Expr '+' Term                                         {$$ = doAdd($1, $3);};
              | Expr '-' Term                                         {$$ = doSub($1, $3);};
              |	Term                                                  {$$ = $1;};
Term		      :	Term '*' Term2	                                      {$$ = doMult($1, $3);};
              | Term '/' Term2                                        {$$ = doDiv($1, $3);};
              | Term '%' Term2                                        {$$ = doMod($1, $3);};
              |	Term2                                                 {$$ = $1;};
Term2         : '-' Term2                                             {$$ = doUnaryMin($2);};
              | NOT Term2                                             {$$ = doNot($2);};
              | Factor '^' Term2                                      {$$ = doExponent($1, $3);};
              | Factor                                                {$$ = $1;};
Factor		    :	IntLit                                                {$$ = doIntLit(yytext);};
              | BoolLit                                               {$$ = doBoolLit(yytext);};
              | StringLit                                             {doStringLit(yytext);};
              |	Id                                                    {$$ = doRval($1); };
              | Id '[' BExpr ']'                                      {$$ = doArrayVal($1, $3);};
              | Id '[' BExpr ']' '[' BExpr ']'                        {$$ = do2DarrayVal($1, $3, $6);};
IdentList     : Id ',' IdentList                                      {$$ = appendIdNode($3, $1);}; 
              | Id                                                    {$$ = createIdNode($1);};
ArraySize     : IntLit                                                {$$ = strdup(yytext);};
Id			      : Ident                                                 {$$ = strdup(yytext);}
 
%%

int yyerror(char *s)  {
  writeIndicator(getCurrentColumnNum());
  writeMessage("Illegal Character in YACC");
}
