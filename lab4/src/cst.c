#include "cst.h"

node *append(node_type type, node *left, node *mid, node *right, int int_val, float float_val, char *id, node_type ntype)
{
    node *n = (node *)malloc(sizeof(node));
    n->type = type;
    n->left = left;
    n->mid = mid;
    n->right = right;
    n->int_val = int_val;
    n->float_val = float_val;
    n->id = id;
    n->ntype = ntype;
    return n;
}

void print_tree(node *root, int depth)
{
    if (root == NULL)
        return;
    for (int i = 0; i < depth; i++)
        printf("  ");
    switch (root->type)
    {
    case Root:
        printf("Root\n");
        print_tree(root->right, depth);
        break;

    case CompUnit:
        printf("CompUnit\n");
        print_tree(root->right, depth + 1);
        print_tree(root->left, depth + 1);
        break;

    case ConstDecl:
        printf("ConstDecl\n");
        print_tree(root->right, depth + 1);
        break;

    case ConstDef:
        printf("ConstDef: %s\n", root->id);
        print_tree(root->mid, depth + 1);
        print_tree(root->right, depth + 1);
        print_tree(root->left, depth + 1);
        break;

    case ConstExpArray:
        printf("ConstExpArray\n");
        print_tree(root->right, depth + 1);
        print_tree(root->left, depth + 1);
        break;

    case ConstInitVal:
        printf("ConstInitVal\n");
        print_tree(root->right, depth + 1);
        print_tree(root->left, depth + 1);
        break;

    case ConstExp:
        printf("ConstExp\n");
        print_tree(root->right, depth + 1);
        if (root->int_val == Plus)
        {
            for (int i = 0; i < depth + 1; i++)
                printf("  ");
            printf("ExpType: +\n");
        }
        else if (root->int_val == Minus)
        {
            for (int i = 0; i < depth + 1; i++)
                printf("  ");
            printf("ExpType: -\n");
        }
        print_tree(root->left, depth + 1);
        break;

    case VarDecl:
        printf("VarDecl\n");
        print_tree(root->right, depth + 1);
        break;

    case VarDef:
        printf("VarDef: %s\n", root->id);
        print_tree(root->mid, depth + 1);
        print_tree(root->right, depth + 1);
        print_tree(root->left, depth + 1);
        break;

    case InitVal:
        printf("InitVal\n");
        print_tree(root->right, depth + 1);
        break;

    case InitVals:
        printf("InitVals\n");
        print_tree(root->right, depth + 1);
        print_tree(root->left, depth + 1);
        break;

    case FuncDef:
        printf("FuncDef: %s\n", root->id);
        print_tree(root->mid, depth + 1);
        print_tree(root->right, depth + 1);
        break;

    case FuncFParam:
        printf("FuncFParam: %s\n", root->id);
        print_tree(root->right, depth + 1);
        print_tree(root->left, depth + 1);
        break;

    case Block:
        printf("Block\n");
        print_tree(root->right, depth + 1);
        break;

    case BlockItem:
        printf("BlockItem\n");
        print_tree(root->right, depth + 1);
        print_tree(root->left, depth + 1);
        break;

    case AssignStmt:
        printf("AssignStmt\n");
        print_tree(root->right, depth + 1);
        print_tree(root->left, depth + 1);
        break;

    case ExpStmt:
        printf("ExpStmt\n");
        print_tree(root->right, depth + 1);
        break;

    case BlockStmt:
        printf("BlankStmt\n");
        print_tree(root->right, depth + 1);
        break;

    case IfStmt:
        printf("IfStmt\n");
        print_tree(root->right, depth + 1);
        print_tree(root->left, depth + 1);
        break;

    case IfElseStmt:
        printf("IfElseStmt\n");
        print_tree(root->right, depth + 1);
        print_tree(root->mid, depth + 1);
        print_tree(root->left, depth + 1);
        break;

    case WhileStmt:
        printf("WhileStmt\n");
        print_tree(root->right, depth + 1);
        print_tree(root->left, depth + 1);
        break;

    case BreakStmt:
        printf("BreakStmt\n");
        break;

    case ContinueStmt:
        printf("ContinueStmt\n");
        break;

    case ReturnStmt:
        printf("ReturnStmt\n");
        print_tree(root->right, depth + 1);
        break;

    case BlankReturnStmt:
        printf("BlankReturnStmt\n");
        break;

    case Exp:
        printf("Exp\n");
        print_tree(root->right, depth + 1);
        break;

    case AddExp:
        printf("AddExp\n");
        print_tree(root->right, depth + 1);
        if (root->int_val == Plus)
        {
            for (int i = 0; i < depth + 1; i++)
                printf("  ");
            printf("ExpType: +\n");
        }
        else if (root->int_val == Minus)
        {
            for (int i = 0; i < depth + 1; i++)
                printf("  ");
            printf("ExpType: -\n");
        }
        print_tree(root->left, depth + 1);
        break;

    case MulExp:
        printf("MulExp\n");
        print_tree(root->right, depth + 1);
        if (root->int_val == Mul)
        {
            for (int i = 0; i < depth + 1; i++)
                printf("  ");
            printf("ExpType: *\n");
        }
        else if (root->int_val == Div)
        {
            for (int i = 0; i < depth + 1; i++)
                printf("  ");
            printf("ExpType: /\n");
        }
        else if (root->int_val == Mod)
        {
            for (int i = 0; i < depth + 1; i++)
                printf("  ");
            printf("ExpType: %%\n");
        }
        print_tree(root->left, depth + 1);
        break;

    case UnaryExp:
        printf("UnaryExp\n");
        if (root->int_val == Not)
        {
            for (int i = 0; i < depth + 1; i++)
                printf("  ");
            printf("ExpType: !\n");
        }
        else if (root->int_val == PLUS)
        {
            for (int i = 0; i < depth + 1; i++)
                printf("  ");
            printf("ExpType: ++\n");
        }
        else if (root->int_val == MINUS)
        {
            for (int i = 0; i < depth + 1; i++)
                printf("  ");
            printf("ExpType: --\n");
        }
        print_tree(root->right, depth + 1);
        break;

    case FuncRParams:
        printf("FuncRParams\n");
        print_tree(root->right, depth + 1);
        print_tree(root->left, depth + 1);
        break;

    case PrimaryExp:
        printf("PrimaryExp\n");
        if (root->ntype == Int)
        {
            for (int i = 0; i < depth + 1; i++)
                printf("  ");
            printf("Int: %d\n", root->int_val);
        }
        else if (root->ntype == Float)
        {
            for (int i = 0; i < depth + 1; i++)
                printf("  ");
            printf("Float: %f\n", root->float_val);
        }
        print_tree(root->right, depth + 1);
        break;

    case LVal:
        printf("LVal: %s\n", root->id);
        print_tree(root->right, depth + 1);
        break;

    case ExpArray:
        printf("ExpArray\n");
        print_tree(root->right, depth + 1);
        print_tree(root->left, depth + 1);
        break;

    case Cond:
        printf("Cond\n");
        print_tree(root->right, depth + 1);
        break;

    case LOrExp:
        printf("LOrExp\n");
        print_tree(root->right, depth + 1);
        if (root->int_val == OR)
        {
            for (int i = 0; i < depth + 1; i++)
                printf("  ");
            printf("ExpType: ||\n");
        }
        print_tree(root->left, depth + 1);
        break;

    case LAndExp:
        printf("LAndExp\n");
        print_tree(root->right, depth + 1);
        if (root->int_val == AND)
        {
            for (int i = 0; i < depth + 1; i++)
                printf("  ");
            printf("ExpType: &&\n");
        }
        print_tree(root->left, depth + 1);
        break;

    case EqExp:
        printf("EqExp\n");
        print_tree(root->right, depth + 1);
        if (root->int_val == EQ)
        {
            for (int i = 0; i < depth + 1; i++)
                printf("  ");
            printf("ExpType: ==\n");
        }
        else if (root->int_val == NE)
        {
            for (int i = 0; i < depth + 1; i++)
                printf("  ");
            printf("ExpType: !=\n");
        }
        print_tree(root->left, depth + 1);
        break;

    case RelExp:
        printf("RelExp\n");
        print_tree(root->right, depth + 1);
        if (root->int_val == LT)
        {
            for (int i = 0; i < depth + 1; i++)
                printf("  ");
            printf("ExpType: <\n");
        }
        else if (root->int_val == GT)
        {
            for (int i = 0; i < depth + 1; i++)
                printf("  ");
            printf("ExpType: >\n");
        }
        else if (root->int_val == LE)
        {
            for (int i = 0; i < depth + 1; i++)
                printf("  ");
            printf("ExpType: <=\n");
        }
        else if (root->int_val == GE)
        {
            for (int i = 0; i < depth + 1; i++)
                printf("  ");
            printf("ExpType: >=\n");
        }
        print_tree(root->left, depth + 1);
        break;

    case NonType:
        printf("NonType\n");
        break;

    default:
        break;
    }
}