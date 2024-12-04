#include <stdio.h>
#include <stdlib.h>
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

node *append(node_type type, node *left, node *mid, node *right, int int_val, float float_val, char *id, node_type ntype);

void print_tree(node *root, int depth);