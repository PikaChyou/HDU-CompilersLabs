%{
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(char *);
%}

%union {
    int int_val;
    float float_val;
    char *str_val;
}

%token <str_val> ID
%token <int_val> INT_LIT
%token <float_val> FLOAT_LIT

%token <int_val> INT FLOAT VOID CONST RETURN IF ELSE WHILE BREAK CONTINUE LP RP LB RB LC RC COMMA SEMICN
%token <int_val> MINUS NOT ASSIGN PLUS MUL DIV MOD AND OR EQ NE LT LE GT GE

%nonassoc ELSE 

%start Root

%%

Root: CompUnit { printf("CompUnit\n"); };

CompUnit: ConstDecl
        | VarDecl
        | FuncDef
        | ConstDecl CompUnit
        | VarDecl CompUnit
        | FuncDef CompUnit
        ;

ConstDecl: CONST INT ConstDef SEMICN
         | CONST FLOAT ConstDef SEMICN
         ;
ConstDef: ID ConstExpArray ASSIGN ConstInitVal                  { printf("ConstDef: %s\n",$1); }
        | ID ConstExpArray ASSIGN ConstInitVal COMMA ConstDef   { printf("ConstDef: %s\n",$1); }
        ;
ConstExpArray: { printf("ConstExpArray\n"); }
             | LB ConstExp RB ConstExpArray { printf("ConstExpArray\n"); }
             ;
ConstInitVal: ConstExp                                  { printf("ConstInitVal\n"); }
            | LC RC                                     { printf("ConstInitVal\n"); }
            | LC ConstInitVal RC                        { printf("ConstInitVal\n"); }
            | LC ConstInitVal COMMA ConstInitVal RC     { printf("ConstInitVal\n"); }
            ;
ConstExp: MulExp { printf("ConstExp\n"); }
        | MulExp PLUS Exp { printf("ConstExp\n"); }
        | MulExp MINUS Exp { printf("ConstExp\n"); }
        ;

VarDecl: INT VarDef SEMICN { printf("VarDecl\n"); }
       | FLOAT VarDef SEMICN { printf("VarDecl\n"); }
       ;
VarDef: ID ConstExpArray                                { printf("VarDef: %s\n",$1); }
      | ID ConstExpArray ASSIGN InitVal                 { printf("VarDef: %s\n",$1); }
      | ID ConstExpArray COMMA VarDef                   { printf("VarDef: %s\n",$1); }
      | ID ConstExpArray ASSIGN InitVal COMMA VarDef    { printf("VarDef: %s\n",$1); }
      ;
InitVal: Exp { printf("InitVal\n"); }
       | LC RC { printf("InitVal\n"); }
       | LC InitVals RC { printf("InitVal\n"); }
       ;
InitVals: InitVal { printf("InitVals\n"); }
        | InitVal COMMA InitVals { printf("InitVals\n"); }
        ;

FuncDef: INT ID LP RP Block                     { printf("FuncDef: %s\n\tFuncType: int\n", $2); }
       | FLOAT ID LP RP Block                   { printf("FuncDef: %s\n\tFuncType: float\n", $2); }
       | VOID ID LP RP Block                    { printf("FuncDef: %s\n\tFuncType: void\n", $2); }
       | INT ID LP FuncFParam RP Block          { printf("FuncDef: %s\n\tFuncType: int\n", $2); }
       | FLOAT ID LP FuncFParam RP Block        { printf("FuncDef: %s\n\tFuncType: float\n", $2); }
       | VOID ID LP FuncFParam RP Block         { printf("FuncDef: %s\n\tFuncType: void\n", $2); }
       ;
FuncFParam: INT ID { printf("\tFuncFParam\n"); }
          | FLOAT ID { printf("FuncFParam\n"); }
          | INT ID LB RB ExpArray { printf("FuncFParam\n"); }
          | FLOAT ID LB RB ExpArray { printf("FuncFParam\n"); }
          | INT ID COMMA FuncFParam { printf("FuncFParam\n"); }
          | FLOAT ID COMMA FuncFParam { printf("FuncFParam\n"); }
          | INT ID LB RB ExpArray COMMA FuncFParam { printf("FuncFParam\n"); }
          | FLOAT ID LB RB ExpArray COMMA FuncFParam { printf("FuncFParam\n"); }
          ;

Block: LC BlockItem RC                  { printf("Block\n"); };
BlockItem:                              { printf("BlockItem\n"); }
         | ConstDecl BlockItem          { printf("BlockItem\n"); }
         | VarDecl BlockItem            { printf("BlockItem\n"); }
         | Stmt BlockItem               { printf("BlockItem\n"); }
         ;

Stmt: LVal ASSIGN Exp SEMICN { printf("Stmt\n"); }
    | Exp SEMICN { printf("Stmt\n"); }
    | Block { printf("Stmt\n"); }
    | IF LP Cond RP Stmt { printf("Stmt\n"); }
    | IF LP Cond RP Stmt ELSE Stmt { printf("Stmt\n"); }
    | WHILE LP Cond RP Stmt { printf("Stmt\n"); }
    | BREAK SEMICN { printf("Stmt\n"); }
    | CONTINUE SEMICN { printf("Stmt\n"); }
    | RETURN SEMICN { printf("Stmt\n"); }
    | RETURN Exp SEMICN { printf("Stmt\n"); }
    ;

Exp: AddExp { printf("Exp\n"); };        
AddExp: MulExp { printf("AddExp\n"); }
      | MulExp PLUS AddExp { printf("AddExp\n"); }
      | MulExp MINUS AddExp { printf("AddExp\n"); }
      ;
MulExp: UnaryExp { printf("MulExp\n"); }
      | UnaryExp MUL MulExp { printf("MulExp\n"); }
      | UnaryExp DIV MulExp { printf("MulExp\n"); }
      | UnaryExp MOD MulExp { printf("MulExp\n"); }
      ;
UnaryExp: PrimaryExp { printf("UnaryExp\n"); }
        | ID LP RP { printf("UnaryExp\n"); }
        | ID LP FuncRParams RP { printf("UnaryExp\n"); }
        | PLUS UnaryExp { printf("UnaryExp\n"); }
        | MINUS UnaryExp { printf("UnaryExp\n"); }
        | NOT UnaryExp { printf("UnaryExp\n"); }
        ;
FuncRParams: Exp { printf("FuncRParams\n"); }
           | Exp COMMA FuncRParams { printf("FuncRParams\n"); }
           ;
PrimaryExp: LP Exp RP { printf("PrimaryExp\n"); }
          | LVal { printf("PrimaryExp\n"); }
          | INT_LIT { printf("PrimaryExp\n"); }
          | FLOAT_LIT { printf("PrimaryExp\n"); }
          ;

LVal: ID ExpArray { printf("LVal\n"); };
ExpArray: { printf("ExpArray\n"); }
        | LB Exp RB ExpArray { printf("ExpArray\n"); }
        ;

Cond: LOrExp { printf("Cond\n"); };
LOrExp: LAndExp { printf("LOrExp\n"); }
      | LAndExp OR LOrExp { printf("LOrExp\n"); }
      ;
LAndExp: EqExp { printf("LAndExp\n"); }
       | EqExp AND LAndExp { printf("LAndExp\n"); }
       ;
EqExp: RelExp { printf("EqExp\n"); }
     | RelExp EQ EqExp { printf("EqExp\n"); }
     | RelExp NE EqExp { printf("EqExp\n"); }
     ;
RelExp: AddExp { printf("RelExp\n"); }
      | AddExp LT RelExp { printf("RelExp\n"); }
      | AddExp GT RelExp { printf("RelExp\n"); }
      | AddExp LE RelExp { printf("RelExp\n"); }
      | AddExp GE RelExp { printf("RelExp\n"); }
      ;

%%

void yyerror(char *str){
    fprintf(stderr,"error:%s\n",str);
}

int main()
{
    yyparse();
}