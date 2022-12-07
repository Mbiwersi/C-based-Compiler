/* Semantics.c
   Support and semantic action routines.
   
*/

#include <string.h>
#include <stdlib.h>

#include "CodeGen.h"
#include "Semantics.h"
#include "SymTab.h"
#include "IOMngr.h"

extern SymTab *table;
extern SymTab *stringTable;
extern SymTab *arrayTable;

/* Semantics support routines */

struct ExprRes *  doIntLit(char * digits)  { 
  // printf("Doing int Lit of '%s'\n", digits);
  struct ExprRes *res;
  
  res = (struct ExprRes *) malloc(sizeof(struct ExprRes));
  res->Reg = AvailTmpReg();
  res->Instrs = GenInstr(NULL,"li",TmpRegName(res->Reg),digits,NULL);

  return res;
}

struct ExprRes * doBoolLit(char * bool) {
  // printf("Doing bool Lit of '%s'\n", bool);

  struct ExprRes * res;
  res = (struct ExprRes *) malloc(sizeof(struct ExprRes));
  res->Reg = AvailTmpReg();

  // see if its true or false
  if(strcmp(bool, "true") == 0){
    // put a non-zero in the reg
    res->Instrs = GenInstr(NULL, "li", TmpRegName(res->Reg), "1", NULL);
  }else if(strcmp(bool, "false") == 0){
    // put 0 in the reg
    res->Instrs = GenInstr(NULL, "li", TmpRegName(res->Reg), "0", NULL);
  }else{
    writeIndicator(getCurrentColumnNum());
    writeMessage("Neither true or false");
  }

  return res;
}

// store the string lit in the a string symtable
void doStringLit(char * string) {
  if(!findName(stringTable, string)) {
    enterName(stringTable, string);
    setCurrentAttr(stringTable, GenLabel());
  }
}

struct ExprRes *  doRval(char * name)  { 

  struct ExprRes *res;

  // printf("Doing Rval name = '%s'\n", name);
  
  if (!findName(table, name)) {
	  writeIndicator(getCurrentColumnNum());
		writeMessage("Undeclared variable");
  }
  res = (struct ExprRes *) malloc(sizeof(struct ExprRes));
  res->Reg = AvailTmpReg();
  res->Instrs = GenInstr(NULL,"lw",TmpRegName(res->Reg),name,NULL);

  return res;
}

extern struct ExprRes * doArrayVal(char * name, struct ExprRes * index) {
  printf("Doing array val of '%s'\n",name);

  struct ExprRes *res;

  if (!findName(table, name)) {
	  writeIndicator(getCurrentColumnNum());
		writeMessage("Undeclared variable");
  }

  res = (struct ExprRes *) malloc(sizeof(struct ExprRes));
  res->Reg = AvailTmpReg();
  res->Instrs = index->Instrs;

  // calculate regoff
  int offsetReg;
  offsetReg = AvailTmpReg();
  AppendSeq(res->Instrs, GenInstr(NULL, "mul", TmpRegName(offsetReg), TmpRegName(index->Reg), "4"));
  AppendSeq(res->Instrs, GenInstr(NULL, "lw", TmpRegName(res->Reg), RegOffwReg(TmpRegName(offsetReg), name), NULL));

  ReleaseTmpReg(index->Reg);
  ReleaseTmpReg(offsetReg);
  // ReleaseTmpReg(res->Reg);
  free(index);

  return res;
}

struct ExprRes * doAdd(struct ExprRes * Res1, struct ExprRes * Res2)  { 

  int reg;
   
  reg = AvailTmpReg();
  AppendSeq(Res1->Instrs,Res2->Instrs);
  AppendSeq(Res1->Instrs,GenInstr(NULL,"add",
                                       TmpRegName(reg),
                                       TmpRegName(Res1->Reg),
                                       TmpRegName(Res2->Reg)));
  ReleaseTmpReg(Res1->Reg);
  ReleaseTmpReg(Res2->Reg);
  Res1->Reg = reg;
  free(Res2);
  return Res1;
}

struct ExprRes * doSub(struct ExprRes * Res1, struct ExprRes * Res2) {
  int reg;

  reg = AvailTmpReg();
  AppendSeq(Res1->Instrs, Res2->Instrs);
  AppendSeq(Res1->Instrs, GenInstr(NULL, "sub", TmpRegName(reg),
                                                TmpRegName(Res1->Reg),
                                                TmpRegName(Res2->Reg)));
  ReleaseTmpReg(Res1->Reg);
  ReleaseTmpReg(Res2->Reg);
  Res1->Reg = reg;
  free(Res2);
  return Res1;
}

struct ExprRes * doMult(struct ExprRes * Res1, struct ExprRes * Res2)  { 

  int reg;
   
  reg = AvailTmpReg();
  AppendSeq(Res1->Instrs,Res2->Instrs);
  AppendSeq(Res1->Instrs,GenInstr(NULL,"mul",
                                       TmpRegName(reg),
                                       TmpRegName(Res1->Reg),
                                       TmpRegName(Res2->Reg)));
  ReleaseTmpReg(Res1->Reg);
  ReleaseTmpReg(Res2->Reg);
  Res1->Reg = reg;
  free(Res2);
  return Res1;
}

struct ExprRes * doDiv(struct ExprRes * Res1, struct ExprRes * Res2) {
  int reg;

  reg = AvailTmpReg();
  AppendSeq(Res1->Instrs, Res2->Instrs);
  AppendSeq(Res1->Instrs, GenInstr(NULL, "div",
                                          TmpRegName(reg),
                                          TmpRegName(Res1->Reg),
                                          TmpRegName(Res2->Reg)));
  ReleaseTmpReg(Res1->Reg);
  ReleaseTmpReg(Res2->Reg);
  Res1->Reg = reg;
  free(Res2);
  return Res1;
}

struct ExprRes * doMod(struct ExprRes * Res1, struct ExprRes * Res2) {
  int reg;

  reg = AvailTmpReg();

  // Do divide
  AppendSeq(Res1->Instrs, Res2->Instrs);
  AppendSeq(Res1->Instrs, GenInstr(NULL, "div",
                                          TmpRegName(reg),
                                          TmpRegName(Res1->Reg),
                                          TmpRegName(Res2->Reg)));
  ReleaseTmpReg(Res1->Reg);
  ReleaseTmpReg(Res2->Reg);
  Res1->Reg = reg;
  free(Res2);

  // get the remainder
  AppendSeq(Res1->Instrs, GenInstr(NULL, "mfhi",
                                          TmpRegName(Res1->Reg),
                                          NULL,
                                          NULL));
  ReleaseTmpReg(Res1->Reg);
  // free()?
  return Res1;
}

struct ExprRes * doUnaryMin(struct ExprRes * Res1) {
  int reg;

  reg = AvailTmpReg();
  // do mult * -1, Can I use the doMult()?
  AppendSeq(Res1->Instrs, GenInstr(NULL, "mul",
                                          TmpRegName(reg),
                                          TmpRegName(Res1->Reg),
                                          "-1"));
  ReleaseTmpReg(Res1->Reg);
  Res1->Reg = reg;
  //free();
  return Res1;
}

struct ExprRes * doExponent(struct ExprRes * Res1, struct ExprRes * Res2) {
  int reg; // needed?

  reg = AvailTmpReg();

  // Reg to help with branch
  int countReg;
  countReg = AvailTmpReg();
  int resultReg;
  resultReg = AvailTmpReg();

  AppendSeq(Res1->Instrs, Res2->Instrs);
  AppendSeq(Res1->Instrs, GenInstr(NULL, "move", TmpRegName(countReg), TmpRegName(Res2->Reg), NULL)); // make a counter
  AppendSeq(Res1->Instrs, GenInstr(NULL, "move",TmpRegName(resultReg), TmpRegName(Res1->Reg), NULL)); // move to a temp result reg

  // need the where to jump label
  char * label = GenLabel();
  char * label2 = GenLabel();
  // case for zero
  char * zerolabel = GenLabel();
  AppendSeq(Res1->Instrs, GenInstr(NULL, "beq", TmpRegName(countReg), "$zero", zerolabel));

  // case for non zero
  AppendSeq(Res1->Instrs, GenInstr(NULL, "sub", TmpRegName(countReg), TmpRegName(countReg), "1")); // decrease counter

  AppendSeq(Res1->Instrs, GenInstr(label, "beq", TmpRegName(countReg), "$zero", label2));
  AppendSeq(Res1->Instrs, GenInstr(NULL, "mul", TmpRegName(resultReg), TmpRegName(resultReg), TmpRegName(Res1->Reg)));
  AppendSeq(Res1->Instrs, GenInstr(NULL, "sub", TmpRegName(countReg), TmpRegName(countReg), "1")); // decrease counter
  AppendSeq(Res1->Instrs, GenInstr(NULL, "j", label, NULL, NULL));
  AppendSeq(Res1->Instrs, GenInstr(zerolabel, "li", TmpRegName(resultReg), "1", NULL));
  AppendSeq(Res1->Instrs, GenInstr(label2, NULL, NULL, NULL, NULL));

  ReleaseTmpReg(Res1->Reg);
  ReleaseTmpReg(Res2->Reg);
  ReleaseTmpReg(countReg);
  Res1->Reg = resultReg;
  ReleaseTmpReg(resultReg);
  free(Res2);
  return Res1;
}

struct InstrSeq * doPrint(struct ExprRes * Expr, char * printAfter) { 

  struct InstrSeq *code;
    
  code = Expr->Instrs;

  // printf("Doing doPrint tmpRegName(Expr->Reg) = '%s'\n", TmpRegName(Expr->Reg));
  
  AppendSeq(code,GenInstr(NULL,"li","$v0","1",NULL));
  AppendSeq(code,GenInstr(NULL,"move","$a0",TmpRegName(Expr->Reg),NULL));
  AppendSeq(code,GenInstr(NULL,"syscall",NULL,NULL,NULL));

  AppendSeq(code,GenInstr(NULL,"li","$v0","4",NULL));
  AppendSeq(code,GenInstr(NULL,"la","$a0","_space",NULL));
  AppendSeq(code,GenInstr(NULL,"syscall",NULL,NULL,NULL));

  ReleaseTmpReg(Expr->Reg);
  free(Expr);

  return code;
}

// loop through the list for all of the vars, make one long sting of instr
extern struct InstrSeq * doRead(struct IdList* list) {
  struct InstrSeq *code;

  code = GenInstr(NULL, "li", "$v0", "5", NULL);
  AppendSeq(code, GenInstr(NULL, "syscall", NULL, NULL, NULL));
  AppendSeq(code,GenInstr(NULL,"sw","$v0", list->Id,NULL));
    
  list = list->Next;
  while(list != NULL) {
    if (!findName(table, list->Id)) {
	    writeIndicator(getCurrentColumnNum());
		  writeMessage("Undeclared variable");
    }

    AppendSeq(code, GenInstr(NULL, "li", "$v0", "5", NULL));
    AppendSeq(code, GenInstr(NULL, "syscall", NULL, NULL, NULL));
    AppendSeq(code, GenInstr(NULL,"sw","$v0", list->Id,NULL));
    
  
    list = list->Next;
  }

  return code;
}

// might need to free up the node after done with it
extern struct IdList * createIdNode(char * varName) {
  struct IdList * node;

  node = (struct IdList *) malloc(sizeof(struct IdList));
  node->Id = varName;
  node->Next = NULL;

  return node;
}

// might need to free up the list after done with it
extern struct IdList * appendIdNode(struct IdList * list, char * varName) {
  struct IdList * newNode = createIdNode(varName);
  newNode->Next = list;

  return newNode;
}

extern struct ExprResList * createExprNode(struct ExprRes * Res1) {
  struct ExprResList * node;

  node = (struct ExprResList *) malloc(sizeof(struct ExprResList));
  node->Expr = Res1;
  node->Next = NULL;

  return node;
}

extern struct ExprResList * appendExprNode(struct ExprRes * Res1, struct ExprResList * list) {
  struct ExprResList * newNode = createExprNode(Res1);
  newNode->Next = list;
  return newNode;
}

extern struct InstrSeq * doPrintList(struct ExprResList * list) {
  struct InstrSeq *code;
  code = doPrint(list->Expr, "_space");
  list = list->Next;
  while(list != NULL){
    AppendSeq(code, doPrint(list->Expr, "_space"));
    list = list->Next;
  }
  return code;
}

extern struct InstrSeq * doPrintLines(struct ExprRes * Expr) {
  struct InstrSeq *code;
    
  code = Expr->Instrs;

  // Reg to help with branch
  int countReg; // is this unessary with the TmpRegName(Expr->Reg)?
  countReg = AvailTmpReg();

  // counter for while statement
  char * label = GenLabel();
  char * label2 = GenLabel();
  AppendSeq(code, GenInstr(NULL, "move", TmpRegName(countReg), TmpRegName(Expr->Reg), NULL)); // make a counter

  // while statement beq
  AppendSeq(code, GenInstr(label, "beq", TmpRegName(countReg), "$zero", label2));
  AppendSeq(code, GenInstr(NULL, "sub", TmpRegName(countReg), TmpRegName(countReg), "1")); // decrease counter

  // print the newline
  AppendSeq(code,GenInstr(NULL,"li","$v0","4",NULL));
  AppendSeq(code,GenInstr(NULL,"la","$a0","_nl",NULL));
  AppendSeq(code,GenInstr(NULL,"syscall",NULL,NULL,NULL));
  // jump back to while statement
  AppendSeq(code, GenInstr(NULL, "j", label, NULL, NULL));
  // label for branch to go to
  AppendSeq(code, GenInstr(label2, NULL, NULL, NULL, NULL));

  ReleaseTmpReg(Expr->Reg);
  ReleaseTmpReg(countReg);
  free(Expr);
  // free(counterReg); // NEEDED?
  return code;
}

extern struct InstrSeq * doPrintSpaces(struct ExprRes * Expr) {
  struct InstrSeq *code;
    
  code = Expr->Instrs;

  // Reg to help with branch
  int countReg; // is this unessary with the TmpRegName(Expr->Reg)?
  countReg = AvailTmpReg();

  // counter for while statement
  char * label = GenLabel();
  char * label2 = GenLabel();
  AppendSeq(code, GenInstr(NULL, "move", TmpRegName(countReg), TmpRegName(Expr->Reg), NULL)); // make a counter

  // while statement beq
  AppendSeq(code, GenInstr(label, "beq", TmpRegName(countReg), "$zero", label2));
  AppendSeq(code, GenInstr(NULL, "sub", TmpRegName(countReg), TmpRegName(countReg), "1")); // decrease counter

  // print the newline
  AppendSeq(code,GenInstr(NULL,"li","$v0","4",NULL));
  AppendSeq(code,GenInstr(NULL,"la","$a0","_space",NULL));
  AppendSeq(code,GenInstr(NULL,"syscall",NULL,NULL,NULL));
  // jump back to while statement
  AppendSeq(code, GenInstr(NULL, "j", label, NULL, NULL));
  // label for branch to go to
  AppendSeq(code, GenInstr(label2, NULL, NULL, NULL, NULL));

  ReleaseTmpReg(Expr->Reg);
  ReleaseTmpReg(countReg);
  free(Expr);
  // free(counterReg); // NEEDED?
  return code;
}

extern struct InstrSeq * doPrintString() {
  struct InstrSeq *code;

  char * string = getCurrentName(stringTable);

  if(findName(stringTable, string)) {
    // write out the string
    code = GenInstr(NULL,"li","$v0","4",NULL);
    AppendSeq(code,GenInstr(NULL,"la","$a0",(char *) getCurrentAttr(stringTable),NULL));
    AppendSeq(code,GenInstr(NULL,"syscall",NULL,NULL,NULL));

  }else {
    writeIndicator(getCurrentColumnNum());
		writeMessage("Did not find string");
  }
  return code;
}

struct InstrSeq * doAssign(char *name, struct ExprRes * Expr) { 

  struct InstrSeq *code;
  
  if (!findName(table, name)) {
	  writeIndicator(getCurrentColumnNum());
		writeMessage("Undeclared variable");
  }

  code = Expr->Instrs;
  
  AppendSeq(code,GenInstr(NULL,"sw",TmpRegName(Expr->Reg), name,NULL));

  ReleaseTmpReg(Expr->Reg);
  free(Expr);
  
  return code;
}

extern struct InstrSeq * doArrayAssign(char * name, struct ExprRes * arrayLoc, struct ExprRes * Expr) {
  struct InstrSeq *code;
  
  if (!findName(table, name)) {
	  writeIndicator(getCurrentColumnNum());
		writeMessage("Undeclared variable");
  }

  code = arrayLoc->Instrs; //////////////////////// FOUND BUG
  AppendSeq(code, Expr->Instrs); ////////////////// THESE WHERE SWAPPED BEFORE, FIXED NOW

  // times the index by 4
  int offsetReg;
  offsetReg = AvailTmpReg();
  AppendSeq(code, GenInstr(NULL, "mul", TmpRegName(offsetReg), TmpRegName(arrayLoc->Reg), "4"));
  AppendSeq(code, GenInstr(NULL, "sw", TmpRegName(Expr->Reg), RegOffwReg(TmpRegName(offsetReg), name), NULL));

  ReleaseTmpReg(Expr->Reg);
  ReleaseTmpReg(offsetReg);
  ReleaseTmpReg(arrayLoc->Reg);
  free(Expr);
  free(arrayLoc);
  return code;
}

extern void enterInt(char * varName) {
  enterName(table, varName);
  setCurrentAttr(table, "int");
}
extern void enterBool(char * varName) {
  enterName(table, varName);
  setCurrentAttr(table, "bool");
}

extern struct ExprRes * doEq(struct ExprRes * Res1,  struct ExprRes * Res2) {
	struct ExprRes * Res;
  int reg = AvailTmpReg();
	AppendSeq(Res1->Instrs, Res2->Instrs);
 	Res = (struct ExprRes *) malloc(sizeof(struct ExprRes));

	AppendSeq(Res1->Instrs, GenInstr(NULL, "seq", TmpRegName(reg), TmpRegName(Res1->Reg), TmpRegName(Res2->Reg)));
  Res->Reg = reg;
	Res->Instrs = Res1->Instrs;
	ReleaseTmpReg(Res1->Reg);
  ReleaseTmpReg(Res2->Reg);
	free(Res1);
	free(Res2);
	return Res;
}

extern struct ExprRes * doNotEq (struct ExprRes * Res1,  struct ExprRes * Res2) {
  struct ExprRes * Res;
  int reg = AvailTmpReg();
	AppendSeq(Res1->Instrs, Res2->Instrs);
 	Res = (struct ExprRes *) malloc(sizeof(struct ExprRes));

	AppendSeq(Res1->Instrs, GenInstr(NULL, "sne", TmpRegName(reg), TmpRegName(Res1->Reg), TmpRegName(Res2->Reg)));
  Res->Reg = reg;
	Res->Instrs = Res1->Instrs;
	ReleaseTmpReg(Res1->Reg);
  ReleaseTmpReg(Res2->Reg);
	free(Res1);
	free(Res2);
	return Res;
}

extern struct ExprRes * doNot (struct ExprRes * Res1) {
  struct ExprRes * Res;
  int reg = AvailTmpReg();
 	Res = (struct ExprRes *) malloc(sizeof(struct ExprRes));

	AppendSeq(Res1->Instrs, GenInstr(NULL, "not", TmpRegName(reg), TmpRegName(Res1->Reg), NULL));
  Res->Reg = reg;
	Res->Instrs = Res1->Instrs;
	ReleaseTmpReg(Res1->Reg);
	free(Res1);
	return Res;
}

extern struct ExprRes * doLT(struct ExprRes * Res1, struct ExprRes * Res2) {
  struct ExprRes * Res;
  int reg = AvailTmpReg();
  AppendSeq(Res1->Instrs, Res2->Instrs);
  Res = (struct ExprRes *) malloc(sizeof(struct ExprRes));

  // do less-than
  AppendSeq(Res1->Instrs, GenInstr(NULL, "slt", TmpRegName(reg), TmpRegName(Res1->Reg), TmpRegName(Res2->Reg)));
  Res->Reg = reg;
  Res->Instrs = Res1->Instrs;
  ReleaseTmpReg(Res1->Reg);
  ReleaseTmpReg(Res2->Reg);
  free(Res1);
  free(Res2);
  return Res;
}

extern struct ExprRes * doLTE (struct ExprRes * Res1, struct ExprRes * Res2) {
  struct ExprRes * Res;
  int reg = AvailTmpReg();
  AppendSeq(Res1->Instrs, Res2->Instrs);
  Res = (struct ExprRes *) malloc(sizeof(struct ExprRes));

  // do less-than or equal
  AppendSeq(Res1->Instrs, GenInstr(NULL, "sle", TmpRegName(reg), TmpRegName(Res1->Reg), TmpRegName(Res2->Reg)));
  Res->Reg = reg;
  Res->Instrs = Res1->Instrs;
  ReleaseTmpReg(Res1->Reg);
  ReleaseTmpReg(Res2->Reg);
  free(Res1);
  free(Res2);
  return Res;
}

extern struct ExprRes * doGT (struct ExprRes * Res1, struct ExprRes * Res2) {
  struct ExprRes * Res;
  int reg = AvailTmpReg();
  AppendSeq(Res1->Instrs, Res2->Instrs);
  Res = (struct ExprRes *) malloc(sizeof(struct ExprRes));

  // do greater-than
  AppendSeq(Res1->Instrs, GenInstr(NULL, "slt", TmpRegName(reg), TmpRegName(Res2->Reg), TmpRegName(Res1->Reg)));
  Res->Reg = reg;
  Res->Instrs = Res1->Instrs;
  ReleaseTmpReg(Res1->Reg);
  ReleaseTmpReg(Res2->Reg);
  free(Res1);
  free(Res2);
  return Res;
}

extern struct ExprRes * doGTE (struct ExprRes * Res1, struct ExprRes * Res2) {
  struct ExprRes * Res;
  int reg = AvailTmpReg();
  AppendSeq(Res1->Instrs, Res2->Instrs);
  Res = (struct ExprRes *) malloc(sizeof(struct ExprRes));

  // do greater-than or equal
  AppendSeq(Res1->Instrs, GenInstr(NULL, "sge", TmpRegName(reg), TmpRegName(Res1->Reg), TmpRegName(Res2->Reg)));
  Res->Reg = reg;
  Res->Instrs = Res1->Instrs;
  ReleaseTmpReg(Res1->Reg);
  ReleaseTmpReg(Res2->Reg);
  free(Res1);
  free(Res2);
  return Res;
}

extern struct ExprRes * doAnd (struct ExprRes * Res1,  struct ExprRes * Res2) {
  struct ExprRes * Res;
  int reg = AvailTmpReg();
  AppendSeq(Res1->Instrs, Res2->Instrs);
  Res = (struct ExprRes *) malloc(sizeof(struct ExprRes));

  // do Logical and
  AppendSeq(Res1->Instrs, GenInstr(NULL, "and", TmpRegName(reg), TmpRegName(Res1->Reg), TmpRegName(Res2->Reg)));
  Res->Reg = reg;

  Res->Instrs = Res1->Instrs;
  ReleaseTmpReg(Res1->Reg);
  ReleaseTmpReg(Res2->Reg);
  free(Res1);
  free(Res2);
  return Res;
}

extern struct ExprRes * doOr (struct ExprRes * Res1,  struct ExprRes * Res2) {
  struct ExprRes * Res;
  int reg = AvailTmpReg();
  AppendSeq(Res1->Instrs, Res2->Instrs);
  Res = (struct ExprRes *) malloc(sizeof(struct ExprRes));

  // do Logical or
  AppendSeq(Res1->Instrs, GenInstr(NULL, "or", TmpRegName(reg), TmpRegName(Res1->Reg), TmpRegName(Res2->Reg)));
  Res->Reg = reg;

  Res->Instrs = Res1->Instrs;
  ReleaseTmpReg(Res1->Reg);
  ReleaseTmpReg(Res2->Reg);
  free(Res1);
  free(Res2);
  return Res;
}

extern struct InstrSeq * doIf(struct ExprRes * Res, struct InstrSeq * seq) {
	struct InstrSeq * seq2;
  char * label = GenLabel();
  AppendSeq(Res->Instrs, GenInstr(NULL, "beq", "$zero", TmpRegName(Res->Reg), label));
	seq2 = AppendSeq(Res->Instrs, seq);
	AppendSeq(seq2, GenInstr(label, NULL, NULL, NULL, NULL));
  ReleaseTmpReg(Res->Reg);
	free(Res);
	return seq2;
}

extern struct InstrSeq * doIfElse(struct ExprRes *bRes, struct InstrSeq * ifSeq, struct InstrSeq * elseSeq) {
  struct InstrSeq * seq2;
  char * elseLabel = GenLabel();
  char * finishLabel = GenLabel();

  // test condition, jump to else if needed
  AppendSeq(bRes->Instrs, GenInstr(NULL, "beq", "$zero", TmpRegName(bRes->Reg), elseLabel));
  seq2 = AppendSeq(bRes->Instrs, ifSeq);

  // Add jump passed else
  AppendSeq(seq2, GenInstr(NULL, "j", finishLabel, NULL, NULL));

  // Append else instructions
  AppendSeq(seq2, GenInstr(elseLabel, NULL, NULL, NULL, NULL));
  AppendSeq(seq2, elseSeq);
  
  // Append finish label to jump to after conclusion of if instructions
  AppendSeq(seq2, GenInstr(finishLabel, NULL, NULL, NULL, NULL));

  ReleaseTmpReg(bRes->Reg);
  free(bRes);

  return seq2;
}

extern struct InstrSeq * doWhile(struct ExprRes *bRes, struct InstrSeq * seq) {
  struct InstrSeq * seq2;
  // create a label to jump to before the condition
  char * label = GenLabel();
  char * label2 = GenLabel();
  seq2 = GenInstr(label, NULL, NULL, NULL, NULL);
  AppendSeq(seq2, bRes->Instrs);
  AppendSeq(seq2, GenInstr(NULL, "beq", "$zero", TmpRegName(bRes->Reg), label2));
  AppendSeq(seq2, seq);
  AppendSeq(seq2, GenInstr(NULL, "j", label, NULL, NULL));
	AppendSeq(seq2, GenInstr(label2, NULL, NULL, NULL, NULL));

  free(bRes);

  return seq2;
}

extern void intArrayDec(char * id, char * size) {
  // printf("int array '%s'\n", id);
  // printf("Size of array %d\n", atoi(size));

  char arraySize[10];
  int newSize = atoi(size)*4;
  snprintf(arraySize, 10, "%d", newSize);

  enterName(table, id);
  setCurrentAttr(table, strdup(arraySize));
}

/*

extern struct InstrSeq * doIf(struct ExprRes *res1, struct ExprRes *res2, struct InstrSeq * seq) {
	struct InstrSeq *seq2;
	char * label;
	label = GenLabel();
	AppendSeq(res1->Instrs, res2->Instrs);
	AppendSeq(res1->Instrs, GenInstr(NULL, "bne", TmpRegName(res1->Reg), TmpRegName(res2->Reg), label));
	seq2 = AppendSeq(res1->Instrs, seq);
	AppendSeq(seq2, GenInstr(label, NULL, NULL, NULL, NULL));
	ReleaseTmpReg(res1->Reg);
  	ReleaseTmpReg(res2->Reg);
	free(res1);
	free(res2);
	return seq2;
}

*/
void Finish(struct InstrSeq *Code) { 
  struct InstrSeq *code;
  //struct SymEntry *entry;
  int hasMore;
  struct Attr * attr;


  code = GenInstr(NULL,".text",NULL,NULL,NULL);
  //AppendSeq(code,GenInstr(NULL,".align","2",NULL,NULL));
  AppendSeq(code,GenInstr(NULL,".globl","main",NULL,NULL));
  AppendSeq(code, GenInstr("main",NULL,NULL,NULL,NULL));
  AppendSeq(code,Code);
  AppendSeq(code, GenInstr(NULL, "li", "$v0", "10", NULL)); 
  AppendSeq(code, GenInstr(NULL,"syscall",NULL,NULL,NULL));
  AppendSeq(code,GenInstr(NULL,".data",NULL,NULL,NULL));

  // allocate space for arrays
  hasMore = startIterator(table);
  while (hasMore) {
    if(!(strcmp(getCurrentAttr(table), "int") == 0 || strcmp(getCurrentAttr(table), "bool") == 0 )) {
      AppendSeq(code, GenInstr((char *) getCurrentName(table),".space", getCurrentAttr(table),NULL,NULL));
    }
    hasMore = nextEntry(table);
  }
  AppendSeq(code,GenInstr(NULL,".align","4",NULL,NULL));
  AppendSeq(code,GenInstr("_nl",".asciiz","\"\\n\"",NULL,NULL));
  AppendSeq(code,GenInstr("_space",".asciiz","\" \"",NULL,NULL));
  AppendSeq(code,GenInstr("_true",".asciiz","\"true\"",NULL,NULL));
  AppendSeq(code,GenInstr("_false",".asciiz","\"false\"",NULL,NULL));

  // print all of the string literals
  hasMore = startIterator(stringTable);
  while (hasMore) {
    AppendSeq(code,GenInstr((char *) getCurrentAttr(stringTable),".asciiz",(char *) getCurrentName(stringTable),NULL,NULL));
    hasMore = nextEntry(stringTable);
  }


 hasMore = startIterator(table);
 while (hasMore) {
  if((strcmp(getCurrentAttr(table), "int") == 0 || strcmp(getCurrentAttr(table), "bool") == 0 )) {
    AppendSeq(code, GenInstr((char *) getCurrentName(table),".word","0",NULL,NULL));
  }
  hasMore = nextEntry(table);
 }
  
  WriteSeq(code);
  
  return;
}




