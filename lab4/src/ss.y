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
Root: CompUnit;
CompUnit: ConstDecl
        | VarDecl
        | FuncDef
        | ConstDecl CompUnit
        | VarDecl CompUnit
        | FuncDef CompUnit;

ConstDecl: CONST INT ConstDef SEMICN
         | CONST FLOAT ConstDef SEMICN;
ConstDef: ID ConstExpArray ASSIGN ConstInitVal
        | ID ConstExpArray ASSIGN ConstInitVal COMMA ConstDef;
ConstExpArray: 
             | LB ConstExp RB ConstExpArray;
ConstInitVal: ConstExp
            | LC RC
            | LC ConstInitVal RC
            | LC ConstInitVal COMMA ConstInitVal RC;
ConstExp: MulExp
        | MulExp PLUS Exp
        | MulExp MINUS Exp;

VarDecl: INT VarDef SEMICN
       | FLOAT VarDef SEMICN;
VarDef: ID ConstExpArray
      | ID ConstExpArray ASSIGN InitVal
      | ID ConstExpArray COMMA VarDef
      | ID ConstExpArray ASSIGN InitVal COMMA VarDef;
InitVal: Exp
       | LC RC
       | LC InitVals RC;
InitVals: InitVal
        | InitVal COMMA InitVals;

FuncDef: INT ID LP RP Block
       | FLOAT ID LP RP Block
       | VOID ID LP RP Block
       | INT ID LP FuncFParam RP Block
       | FLOAT ID LP FuncFParam RP Block
       | VOID ID LP FuncFParam RP Block;
FuncFParam: INT ID
          | FLOAT ID
          | INT ID LB RB ExpArray
          | FLOAT ID LB RB ExpArray
          | INT ID COMMA FuncFParam
          | FLOAT ID COMMA FuncFParam
          | INT ID LB RB ExpArray COMMA FuncFParam
          | FLOAT ID LB RB ExpArray COMMA FuncFParam;

Block: LC BlockItem RC;
BlockItem: 
         | ConstDecl BlockItem
         | VarDecl BlockItem
         | Stmt BlockItem;

Stmt: LVal ASSIGN Exp SEMICN
    | Exp SEMICN
    | Block
    | IF LP Cond RP Stmt
    | IF LP Cond RP Stmt ELSE Stmt
    | WHILE LP Cond RP Stmt
    | BREAK SEMICN
    | CONTINUE SEMICN
    | RETURN SEMICN
    | RETURN Exp SEMICN;

Exp: AddExp;
AddExp: MulExp
      | MulExp PLUS AddExp
      | MulExp MINUS AddExp;
MulExp: UnaryExp
      | UnaryExp MUL MulExp
      | UnaryExp DIV MulExp
      | UnaryExp MOD MulExp;
UnaryExp: PrimaryExp
        | ID LP RP
        | ID LP FuncRParams RP
        | PLUS UnaryExp
        | MINUS UnaryExp
        | NOT UnaryExp;
FuncRParams: Exp
           | Exp COMMA FuncRParams;
PrimaryExp: LP Exp RP
          | LVal
          | INT_LIT
          | FLOAT_LIT;
LVal: ID ExpArray;

Cond: LOrExp;
LOrExp: LAndExp
      | LAndExp OR LOrExp;
LAndExp: EqExp
       | EqExp AND LAndExp;
EqExp: RelExp
     | RelExp EQ EqExp
     | RelExp NE EqExp;
RelExp: AddExp
      | AddExp LT RelExp
      | AddExp GT RelExp
      | AddExp LE RelExp
      | AddExp GE RelExp;

ExpArray: 
        | LB Exp RB ExpArray;

%%

void yyerror(char *str){
    fprintf(stderr,"error:%s\n",str);
}

int main()
{
    yyparse();
}