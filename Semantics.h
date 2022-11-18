/* Semantic Records */
struct IdList {
 struct SymEntry * TheEntry;
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

/* Semantics Actions */
extern struct ExprRes * doIntLit(char * digits);
extern struct ExprRes * doRval(char * name);
extern struct InstrSeq * doAssign(char * name, struct ExprRes * Res1);
extern struct ExprRes * doAdd(struct ExprRes * Res1, struct ExprRes * Res2);
extern struct ExprRes * doMult(struct ExprRes * Res1, struct ExprRes * Res2);
extern struct InstrSeq * doPrint(struct ExprRes * Expr);
extern struct ExprRes * doEQ (struct ExprRes * Res1, struct ExprRes * Res2);
extern struct InstrSeq * doIf(struct BExprRes *bRes, struct InstrSeq * seq);
extern void Finish(struct InstrSeq *Code);