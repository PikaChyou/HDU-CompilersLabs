#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "y.tab.h"

typedef enum node_type
{
    Root,
    CompUnit,
    ConstDecl,
    ConstDef,
    ConstExpArray,
    ConstInitVal,
    ConstExp,
    VarDecl,
    VarDef,
    InitVal,
    InitVals,
    FuncDef,
    FuncFParam,
    Block,
    BlockItem,
    AssignStmt,
    ExpStmt,
    BlockStmt,
    IfStmt,
    IfElseStmt,
    WhileStmt,
    BreakStmt,
    ContinueStmt,
    ReturnStmt,
    BlankReturnStmt,
    Exp,
    AddExp,
    MulExp,
    UnaryExp,
    FuncRParams,
    PrimaryExp,
    LVal,
    ExpArray,
    Cond,
    LOrExp,
    LAndExp,
    EqExp,
    RelExp,
    NonType,
    Float,
    Int,
    Void,
    Plus,
    Minus,
    Mul,
    Div,
    Mod,
    Not,
} node_type;

typedef struct Node
{
    node_type type;
    struct Node *left;
    struct Node *mid;
    struct Node *right;
    int int_val;
    float float_val;
    char *id;
    node_type ntype;
} node;

typedef enum Symbol_Type
{
    Func,
    Var,
    Param
} symbol_type;

typedef struct Symbol
{
    char *name;
    symbol_type type;
    struct Symbol *next;
} Symbol;

node *append(node_type type, node *left, node *mid, node *right, int int_val, float float_val, char *id, node_type ntype);

void print_tree(node *root, int depth);

bool add_symbol(const char *name, symbol_type type);

bool check_symbol(const char *name, symbol_type type);
