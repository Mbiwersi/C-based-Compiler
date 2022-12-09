/* Semantics.h
   The action and supporting routines for performing semantics processing.
*/

/* Semantic Records */
struct IdList {
  char * Id;
  struct IdList * Next;
};

struct ExprRes {
  int Reg;
  struct InstrSeq * Instrs;
};

struct ExprResList {
	struct ExprRes *Expr;
	struct ExprResList * Next;
};

struct Attr {
  char * type;
  void * values;
};

struct Array {
  int spaceNeeded;
  int rows;
  int cols;
};




/* Semantics Actions */

/* Literals */
extern struct ExprRes *  doIntLit(char * digits);
extern struct ExprRes * doBoolLit(char * bool);
extern void doStringLit(char * string);
extern struct ExprRes *  doRval(char * name);
extern void enterInt(char * varName);
extern void enterBool(char * varName);

/* Arithmetic Operators */
extern struct InstrSeq *  doAssign(char * name,  struct ExprRes * Res1);
extern struct ExprRes *  doAdd(struct ExprRes * Res1,  struct ExprRes * Res2);
extern struct ExprRes * doSub(struct ExprRes * Res1, struct ExprRes * Res2);
extern struct ExprRes *  doMult(struct ExprRes * Res1,  struct ExprRes * Res2);
extern struct ExprRes * doDiv(struct ExprRes * Res1, struct ExprRes * Res2);
extern struct ExprRes * doMod(struct ExprRes * Res1, struct ExprRes * Res2);
extern struct ExprRes * doUnaryMin(struct ExprRes * Res1);
extern struct ExprRes * doExponent(struct ExprRes * Res1, struct ExprRes * Res2);

/* I/O */
extern struct InstrSeq *  doPrint(struct ExprRes * Expr, char * printAfter);
extern struct InstrSeq *  doRead(struct IdList* list);
extern struct InstrSeq * doPrintList(struct ExprResList * list);
extern struct InstrSeq * doPrintLines(struct ExprRes * Expr);
extern struct InstrSeq * doPrintSpaces(struct ExprRes * Expr);
extern struct InstrSeq * doPrintString();

/* Relational Operators */
extern struct ExprRes * doEq (struct ExprRes * Res1,  struct ExprRes * Res2);
extern struct ExprRes * doNotEq (struct ExprRes * Res1,  struct ExprRes * Res2);
extern struct ExprRes * doNot (struct ExprRes * Res1);
extern struct ExprRes * doLT (struct ExprRes * Res1, struct ExprRes * Res2);
extern struct ExprRes * doLTE (struct ExprRes * Res1, struct ExprRes * Res2);
extern struct ExprRes * doGT (struct ExprRes * Res1, struct ExprRes * Res2);
extern struct ExprRes * doGTE (struct ExprRes * Res1, struct ExprRes * Res2);
extern struct ExprRes * doAnd (struct ExprRes * Res1,  struct ExprRes * Res2);
extern struct ExprRes * doOr (struct ExprRes * Res1,  struct ExprRes * Res2);

/* Control Structures */
extern struct InstrSeq * doIf(struct ExprRes *bRes, struct InstrSeq * seq);
extern struct InstrSeq * doIfElse(struct ExprRes *bRes, struct InstrSeq * seq, struct InstrSeq * seq2);
extern struct InstrSeq * doWhile(struct ExprRes *bRes, struct InstrSeq * seq);

/* 1D Arrays */
extern void arrayDec(char * id, char * size);
extern struct ExprRes * doArrayVal(char * name, struct ExprRes * index);
extern struct InstrSeq * doArrayAssign(char * name, struct ExprRes * arrayLoc, struct ExprRes * result);

/* 2D Arrays */
extern void twoDArrayDec(char * name, char * rows, char * cols);
extern struct ExprRes * do2DarrayVal(char * name, struct ExprRes * rowIndex, struct ExprRes * colIndex);
extern struct InstrSeq * do2DArrayAssign(char * name, struct ExprRes * index1, struct ExprRes * index2, struct ExprRes * result);

/* Functions */
extern void doFunctionDec(char * name, struct InstrSeq * seq);
extern struct InstrSeq * doFucntionCall(char * name);

/* Extras */
extern struct IdList * createIdNode(char * varName);
extern struct IdList * appendIdNode(struct IdList * list, char * varName);
extern struct ExprResList * createExprNode(struct ExprRes * Res1);
extern struct ExprResList * appendExprNode(struct ExprRes * Res1, struct ExprResList * list);
void printSymTable();
extern void	Finish(struct InstrSeq *Code);
