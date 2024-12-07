%{

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include "cst.h"
#include "lex.yy.h"

int yylex(void);

typedef const enum Error_type{
    Undefined,
    VarUndecleared,
    VarRedecleared,
    FuncUndecleared,
    FuncRedecleared,
    UseVarAsFunc,
    UseFuncAsVar,
    Stmt_Error
} Error_type;

void yyerror(const char *, ...);

extern bool error_flag;

node *root;

int error_cur_line = -1;

extern Symbol *symbol_table;

%}

%union {
    int int_val;
    float float_val;
    char *str_val;
    struct Node *node_val;
}

%token <str_val> ID
%token <int_val> INT_LIT
%token <float_val> FLOAT_LIT

%token <int_val> INT FLOAT VOID CONST RETURN IF ELSE WHILE BREAK CONTINUE LP RP LB RB LC RC COMMA SEMICN
%token <int_val> MINUS NOT ASSIGN PLUS MUL DIV MOD AND OR EQ NE LT LE GT GE

%type <node_val> CompUnit ConstDecl VarDecl FuncDef ConstDef ConstInitVal VarDef InitVal FuncFParam ConstExpArray Block
%type <node_val> Root BlockItem Stmt LVal PrimaryExp UnaryExp FuncRParams MulExp Exp RelExp EqExp LAndExp Cond ConstExp
%type <node_val> ExpArray AddExp LOrExp InitVals

%nonassoc ELSE 

%start Root

%%

Root: CompUnit { root = append(Root, NULL, NULL, $1, 0, 0, NULL, NonType); };

CompUnit: ConstDecl             { $$ = append(CompUnit, NULL, NULL, $1, 0, 0, NULL, NonType); }
        | VarDecl               { $$ = append(CompUnit, NULL, NULL, $1, 0, 0, NULL, NonType); }
        | FuncDef               { $$ = append(CompUnit, NULL, NULL, $1, 0, 0, NULL, NonType); }
        | ConstDecl CompUnit    { $$ = append(CompUnit, $2, NULL, $1, 0, 0, NULL, NonType); }
        | VarDecl CompUnit      { $$ = append(CompUnit, $2, NULL, $1, 0, 0, NULL, NonType); }
        | FuncDef CompUnit      { $$ = append(CompUnit, $2, NULL, $1, 0, 0, NULL, NonType); }
        ;

ConstDecl: CONST INT ConstDef SEMICN    { $$ = append(ConstDecl, NULL, NULL, $3, 0, 0, NULL, Int); }
         | CONST FLOAT ConstDef SEMICN  {  $$ = append(ConstDecl, NULL, NULL, $3, 0, 0, NULL, Float); }
         ;

ConstDef: ID ConstExpArray ASSIGN ConstInitVal                  { 
                                                                    if(!check_symbol($1, Var)) 
                                                                        add_symbol($1, Var);
                                                                    else
                                                                        yyerror($1, VarRedecleared);
                                                                    $$ = append(ConstDef, NULL, $2, $4, 0, 0, $1, NonType); 
                                                                }
        | ID ConstExpArray ASSIGN ConstInitVal COMMA ConstDef   { 
                                                                    if(!check_symbol($1, Var)) 
                                                                        add_symbol($1, Var);
                                                                    else
                                                                        yyerror($1, VarRedecleared);
                                                                    $$ = append(ConstDef, $6, $2, $4, 0, 0, $1, NonType); 
                                                                }
        ;

ConstExpArray: /* empty */                      { $$ = NULL; }
             | LB ConstExp RB ConstExpArray     { $$ = append(ConstExpArray, $4, NULL, $2, 0, 0, NULL, NonType); }
             ;

ConstInitVal: ConstExp                                  { $$ = append(ConstInitVal, NULL, NULL, $1, 0, 0, NULL, NonType); }
            | LC RC                                     { $$ = append(ConstInitVal, NULL, NULL, NULL, 0, 0, NULL, NonType); }
            | LC ConstInitVal RC                        { $$ = append(ConstInitVal, NULL, NULL, $2, 0, 0, NULL, NonType); }
            | LC ConstInitVal COMMA ConstInitVal RC     { $$ = append(ConstInitVal, $4, NULL, $2, 0, 0, NULL, NonType); }
            ;

ConstExp: MulExp                { $$ = append(ConstExp, NULL, NULL, $1, 0, 0, NULL, NonType); }
        | MulExp PLUS Exp       { $$ = append(ConstExp, $3, NULL, $1, PLUS, 0, NULL, NonType); }
        | MulExp MINUS Exp      { $$ = append(ConstExp, $3, NULL, $1, MINUS, 0, NULL, NonType); }
        ;

VarDecl: INT VarDef SEMICN      { $$ = append(VarDecl, NULL, NULL, $2, 0, 0, NULL, Int); }
       | FLOAT VarDef SEMICN    { $$ = append(VarDecl, NULL, NULL, $2, 0, 0, NULL, Float); }
       ;
       
VarDef: ID ConstExpArray                                { 
                                                            if(!check_symbol($1, Var)) 
                                                                add_symbol($1, Var);
                                                            else
                                                                yyerror($1, VarRedecleared);
                                                            $$ = append(VarDef, NULL, $2, NULL, 0, 0, $1, NonType); 
                                                        }
      | ID ConstExpArray ASSIGN InitVal                 { 
                                                            if(!check_symbol($1, Var)) 
                                                                add_symbol($1, Var);
                                                            else
                                                                yyerror($1, VarRedecleared);
                                                            $$ = append(VarDef, NULL, $2, $4, 0, 0, $1, NonType); 
                                                        }
      | ID ConstExpArray COMMA VarDef                   { 
                                                            if(!check_symbol($1, Var)) 
                                                                add_symbol($1, Var);
                                                            else
                                                                yyerror($1, VarRedecleared);
                                                            $$ = append(VarDef, $4, $2, NULL, 0, 0, $1, NonType); 
                                                        }
      | ID ConstExpArray ASSIGN InitVal COMMA VarDef    { 
                                                            if(!check_symbol($1, Var)) 
                                                                add_symbol($1, Var);
                                                            else
                                                                yyerror($1, VarRedecleared);
                                                            $$ = append(VarDef, $6, $2, $4, 0, 0, $1, NonType); 
                                                        }
      ;

InitVal: Exp            { $$ = append(InitVal, NULL, NULL, $1, Exp, 0, NULL, NonType); }
       | LC RC          { $$ = append(InitVal, NULL, NULL, NULL, InitVals, 0, NULL, NonType); }
       | LC InitVals RC { $$ = append(InitVal, NULL, NULL, $2, InitVals, 0, NULL, NonType); }
       ;

InitVals: InitVal                       { $$ = append(InitVals, NULL, NULL, $1, 0, 0, NULL, NonType); }
        | InitVal COMMA InitVals        { $$ = append(InitVals, $3, NULL, $1, 0, 0, NULL, NonType); }
        ;

FuncDef: INT ID LP RP Block                     { 
                                                    if(!check_symbol($2, Func)) 
                                                        add_symbol($2, Func);
                                                    else
                                                        yyerror($2, FuncRedecleared);
                                                    $$ = append(FuncDef, NULL, NULL, $5, 0, 0, $2, Int); 
                                                }
       | FLOAT ID LP RP Block                   { 
                                                    if(!check_symbol($2, Func)) 
                                                        add_symbol($2, Func);
                                                    else
                                                        yyerror($2, FuncRedecleared);
                                                    $$ = append(FuncDef, NULL, NULL, $5, 0, 0, $2, Float); 
                                                }
       | VOID ID LP RP Block                    { 
                                                    if(!check_symbol($2, Func)) 
                                                        add_symbol($2, Func);
                                                    else
                                                        yyerror($2, FuncRedecleared);
                                                    $$ = append(FuncDef, NULL, NULL, $5, 0, 0, $2, Void); 
                                                }
       | INT ID LP FuncFParam RP Block          { 
                                                    if(!check_symbol($2, Func)) 
                                                        add_symbol($2, Func);
                                                    else
                                                        yyerror($2, FuncRedecleared);
                                                    $$ = append(FuncDef, NULL, $4, $6, 0, 0, $2, Int); 
                                                }
       | FLOAT ID LP FuncFParam RP Block        { 
                                                    if(!check_symbol($2, Func)) 
                                                        add_symbol($2, Func);
                                                    else
                                                        yyerror($2, FuncRedecleared);
                                                    $$ = append(FuncDef, NULL, $4, $6, 0, 0, $2, Float); 
                                                }
       | VOID ID LP FuncFParam RP Block         { 
                                                    if(!check_symbol($2, Func)) 
                                                        add_symbol($2, Func);
                                                    else
                                                        yyerror($2, FuncRedecleared);
                                                    $$ = append(FuncDef, NULL, $4, $6, 0, 0, $2, Void); 
                                                }
       ;

FuncFParam: INT ID                                      { 
                                                            if(!check_symbol($2,Param))
                                                                add_symbol($2,Param);
                                                            $$ = append(FuncFParam, NULL, NULL, NULL, 0, 0, $2, Int); 
                                                        }
          | FLOAT ID                                    { 
                                                            if(!check_symbol($2,Param))
                                                                add_symbol($2,Param);
                                                            $$ = append(FuncFParam, NULL, NULL, NULL, 0, 0, $2, Float); 
                                                        }
          | INT ID LB RB ExpArray                       { 
                                                            if(!check_symbol($2,Param))
                                                                add_symbol($2,Param);
                                                            $$ = append(FuncFParam, NULL, NULL, $5, 0, 0, $2, Int); 
                                                        }
          | FLOAT ID LB RB ExpArray                     { 
                                                            if(!check_symbol($2,Param))
                                                                add_symbol($2,Param);
                                                            $$ = append(FuncFParam, NULL, NULL, $5, 0, 0, $2, Float); 
                                                        }
          | INT ID COMMA FuncFParam                     {   
                                                            if(!check_symbol($2,Param))
                                                                add_symbol($2,Param);
                                                            $$ = append(FuncFParam, $4, NULL, NULL, 0, 0, $2, Int); 
                                                        }
          | FLOAT ID COMMA FuncFParam                   { 
                                                            if(!check_symbol($2,Param))
                                                                add_symbol($2,Param);
                                                            $$ = append(FuncFParam, $4, NULL, NULL, 0, 0, $2, Float); 
                                                        }
          | INT ID LB RB ExpArray COMMA FuncFParam      {
                                                            if(!check_symbol($2,Param))
                                                                add_symbol($2,Param);
                                                            $$ = append(FuncFParam, $7, NULL, $5, 0, 0, $2, Int); 
                                                        }
          | FLOAT ID LB RB ExpArray COMMA FuncFParam    { 
                                                            if(!check_symbol($2,Param))
                                                                add_symbol($2,Param);
                                                            $$ = append(FuncFParam, $7, NULL, $5, 0, 0, $2, Float); 
                                                        }
          ;

Block: LC BlockItem RC { $$ = append(Block, NULL, NULL, $2, 0, 0, NULL, NonType); };

BlockItem: /* empty */          { $$ = NULL; }
         | ConstDecl BlockItem  { $$ = append(BlockItem, $2, NULL, $1, 0, 0, NULL, NonType); }
         | VarDecl BlockItem    { $$ = append(BlockItem, $2, NULL, $1, 0, 0, NULL, NonType); }
         | Stmt BlockItem       { $$ = append(BlockItem, $2, NULL, $1, 0, 0, NULL, NonType); }
         ;

Stmt: LVal ASSIGN Exp SEMICN         { $$ = append(AssignStmt, $3, NULL, $1, 0, 0, NULL, NonType); }
    | Exp SEMICN                     { $$ = append(ExpStmt, NULL, NULL, $1, 0, 0, NULL, NonType); }
    | Block                          { $$ = append(BlockStmt, NULL, NULL, $1, 0, 0, NULL, NonType); }
    | IF LP Cond RP Stmt             { $$ = append(IfStmt, $5, NULL, $3, 0, 0, NULL, NonType); }
    | IF LP Cond RP Stmt ELSE Stmt   { $$ = append(IfElseStmt, $7, $5, $3, 0, 0, NULL, NonType); }
    | WHILE LP Cond RP Stmt          { $$ = append(WhileStmt, $5, NULL, $3, 0, 0, NULL, NonType); }
    | BREAK SEMICN                   { $$ = append(BreakStmt, NULL, NULL, NULL, 0, 0, NULL, NonType); }
    | CONTINUE SEMICN                { $$ = append(ContinueStmt, NULL, NULL, NULL, 0, 0, NULL, NonType); }
    | RETURN Exp SEMICN              { $$ = append(ReturnStmt, NULL, NULL, $2, 0, 0, NULL, NonType); }
    | RETURN SEMICN                  { $$ = append(BlankReturnStmt, NULL, NULL, NULL, 0, 0, NULL, NonType); }
    | error                          { 
                                        if(error_cur_line != yylineno) 
                                        {
                                            yyerror("", Stmt_Error);
                                            error_cur_line = yylineno;
                                        } 
                                        yyclearin; 
                                        yyerrok; 
                                     }
    ;

Exp: AddExp     { $$ = append(Exp, NULL, NULL, $1, 0, 0, NULL, NonType); };

AddExp: MulExp                  { $$ = append(AddExp, NULL, NULL, $1, Mul, 0, NULL, NonType); }
      | MulExp PLUS AddExp      { $$ = append(AddExp, $3, NULL, $1, Plus, 0, NULL, NonType); }
      | MulExp MINUS AddExp     { $$ = append(AddExp, $3, NULL, $1, Minus, 0, NULL, NonType); }
      ;

MulExp: UnaryExp                { $$ = append(MulExp, NULL, NULL, $1, UnaryExp, 0, NULL, NonType); }
      | UnaryExp MUL MulExp     { $$ = append(MulExp, $3, NULL, $1, Mul, 0, NULL, NonType); }
      | UnaryExp DIV MulExp     { $$ = append(MulExp, $3, NULL, $1, Div, 0, NULL, NonType); }
      | UnaryExp MOD MulExp     { $$ = append(MulExp, $3, NULL, $1, Mod, 0, NULL, NonType); }
      ;

UnaryExp: PrimaryExp            { $$ = append(UnaryExp, NULL, NULL, $1, PrimaryExp, 0, NULL, NonType); }
        | ID LP RP              { 
                                    if(check_symbol($1, Var))
                                        yyerror($1, UseVarAsFunc);
                                    else if(!check_symbol($1, Func))
                                        yyerror($1, FuncUndecleared);
                                    $$ = append(UnaryExp, NULL, NULL, NULL, FuncRParams, 0, $1, NonType); 
                                }
        | ID LP FuncRParams RP  { 
                                    if(check_symbol($1, Var))
                                        yyerror($1, UseVarAsFunc);
                                    else if(!check_symbol($1, Func))
                                        yyerror($1, FuncUndecleared);
                                    $$ = append(UnaryExp, NULL, NULL, $3, FuncRParams, 0, $1, NonType); 
                                }
        | PLUS UnaryExp         { $$ = append(UnaryExp, NULL, NULL, $2, PLUS, 0, NULL, NonType); }
        | MINUS UnaryExp        { $$ = append(UnaryExp, NULL, NULL, $2, MINUS, 0, NULL, NonType); }
        | NOT UnaryExp          { $$ = append(UnaryExp, NULL, NULL, $2, Not, 0, NULL, NonType); }
        ;
        
FuncRParams: Exp                        { $$ = append(FuncRParams, NULL, NULL, $1, 0, 0, NULL, NonType); }
           | Exp COMMA FuncRParams      { $$ = append(FuncRParams, $3, NULL, $1, 0, 0, NULL, NonType); }
           ;

PrimaryExp: LP Exp RP   { $$ = append(PrimaryExp, NULL, NULL, $2, Exp, 0, NULL, NonType); }
          | LVal        { $$ = append(PrimaryExp, NULL, NULL, $1, LVal, 0, NULL, NonType); }
          | INT_LIT     { $$ = append(PrimaryExp, NULL, NULL, NULL, $1, 0, NULL, Int); }
          | FLOAT_LIT   { $$ = append(PrimaryExp, NULL, NULL, NULL, 0, $1, NULL, Float); }
          ;

LVal: ID ExpArray       { 
                            if(check_symbol($1, Func))
                                yyerror($1, UseFuncAsVar);
                            else if(!check_symbol($1,Var) && !check_symbol($1,Param))
                                yyerror($1, VarUndecleared); 
                            $$ = append(LVal, NULL, NULL, $2, 0, 0, $1, NonType); 
                        };

Cond: LOrExp            { $$ = append(Cond, NULL, NULL, $1, 0, 0, NULL, NonType); };

LOrExp: LAndExp                 { $$ = append(Cond, NULL, NULL, $1, 0, 0, NULL, NonType); }
      | LAndExp OR LOrExp       { $$ = append(Cond, $3, NULL, $1, OR, 0, 0, NonType); }
      ;

LAndExp: EqExp                  { $$ = append(LAndExp, NULL, NULL, $1, 0, 0, NULL, NonType); }
       | EqExp AND LAndExp      { $$ = append(LAndExp, $3, NULL, $1, AND, 0, NULL, NonType); }
       ;

EqExp: RelExp           { $$ = append(EqExp, NULL, NULL, $1, 0, 0, NULL, NonType); }
     | RelExp EQ EqExp  { $$ = append(EqExp, $3, NULL, $1, EQ, 0, NULL, NonType); }
     | RelExp NE EqExp  { $$ = append(EqExp, $3, NULL, $1, NE, 0, NULL, NonType); }
     ;

RelExp: AddExp           { $$ = append(RelExp, NULL, NULL, $1, 0, 0, NULL, NonType); }
      | AddExp LT RelExp { $$ = append(RelExp, $3, NULL, $1, LT, 0, NULL, NonType); }
      | AddExp GT RelExp { $$ = append(RelExp, $3, NULL, $1, GT, 0, NULL, NonType); }
      | AddExp LE RelExp { $$ = append(RelExp, $3, NULL, $1, LE, 0, NULL, NonType); }
      | AddExp GE RelExp { $$ = append(RelExp, $3, NULL, $1, GE, 0, NULL, NonType); }
      ;

ExpArray: /* empty */           { $$ = NULL; }
        | LB Exp RB ExpArray    { $$ = append(ExpArray, $4, NULL, $2, 0, 0, NULL, NonType); }
        ;

%%

void yyerror(const char *fmt, ...)
{
    extern int yylineno;
    extern char *yytext;
    extern int yychar;

    va_list args;
    va_start(args, fmt);

    if(fmt!="syntax error")
        switch(va_arg(args, int))
        {
            case VarUndecleared:
                fprintf(stderr, "Error type %d at line %d : var '%s' undeclared\n", VarUndecleared, yylineno, fmt);
                break;
            case VarRedecleared:
                fprintf(stderr, "Error type %d at line %d : var '%s' redeclared\n", VarRedecleared, yylineno, fmt);
                break;
            case FuncUndecleared:
                fprintf(stderr, "Error type %d at line %d : func '%s' undeclared\n", FuncUndecleared, yylineno, fmt);
                break;
            case FuncRedecleared:
                fprintf(stderr, "Error type %d at line %d : func '%s' redeclared\n", FuncRedecleared, yylineno, fmt);
                break;
            case UseVarAsFunc:
                fprintf(stderr, "Error type %d at line %d : var '%s' be used as func\n", UseVarAsFunc, yylineno, fmt);
                break;
            case UseFuncAsVar:
                fprintf(stderr, "Error type %d at line %d : func '%s' be used as var\n", UseFuncAsVar, yylineno, fmt);
                break;
            case Stmt_Error:
                fprintf(stderr, "Error type %d at line %d : semantic error\n", Stmt_Error, yylineno);
                break;
            default:
                fprintf(stderr, "Undefined error at line %d : %s\n", yylineno, fmt);
        }
        /* fprintf(stderr, "Error type %d at line %d : '%s'\n", va_arg(args, int), yylineno, fmt); */

    va_end(args);

    error_flag = true;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f)
    {
        perror("fopen");
        return 1;
    }

    YY_BUFFER_STATE bp = yy_create_buffer(f, YY_BUF_SIZE);
    yy_switch_to_buffer(bp);

    yyparse();

    yy_delete_buffer(bp);

    fclose(f);

    if(!error_flag) 
        print_tree(root,0);
    return 0;
}