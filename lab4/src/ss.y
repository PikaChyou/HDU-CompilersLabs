%{
%}

%union {
    int intval;
    float floatval;
    char* id;
}

%token <intval> INT
%token <floatval> FLOAT
%token <id> Ident
%token <intval> IntConst
%token <floatval> floatConst

%token 
    CONST VOID
    IF ELSE WHILE BREAK CONTINUE RETURN
    OR AND NOT
    EQ NE
    LT LE GT GE
    ADD SUB
    MUL DIV MOD

%%

CompUnit
    : CompUnit Decl
    | CompUnit FuncDef
    | Decl
    | FuncDef
    ;

Decl
    : ConstDecl
    | VarDecl
    ;

ConstDecl
    : CONST BType ConstDecls ';'
    ;

ConstDecls
    : ConstDef
    | ConstDecls ',' ConstDef
    ;

BType
    : INT
    | FLOAT
    ;

ConstDef
    : Ident ConstArrayPart '=' ConstInitVal
    ;

ConstArrayPart
    : /* empty */
    | '[' ConstExp ']'
    | '[' ConstExp ']' ConstArrayPart 
    ;

ConstInitVal
    : ConstExp
    | '{' '}'
    | '{' ConstInitVals '}'
    ;

ConstInitVals
    : ConstInitVal
    | ConstInitVals ',' ConstInitVal
    ;

VarDecl
    : BType VarDefs ';'
    ;

VarDefs
    : VarDef
    | VarDefs ',' VarDef
    ;

VarDef
    : Ident VarArrayPart
    | Ident VarArrayPart '=' InitVal
    ;

VarArrayPart
    : '[' ConstExp ']'
    | VarArrayPart '[' ConstExp ']'
    ;

InitVal
    : Exp
    | '{' InitVals '}'
    ;

InitVals
    : /* empty */
    | InitVal
    | InitVals ',' InitVal
    ;

FuncDef
    : FuncType Ident '(' ')' Block
    | FuncType Ident '(' FuncFParams ')' Block
    ;

FuncType
    : VOID
    | INT
    | FLOAT
    ;

FuncFParams
    : FuncFParam
    | FuncFParams ',' FuncFParam
    ;

FuncFParam
    : BType Ident sub_FuncFParam
    ;

sub_FuncFParam
    : /* empty */
    | '[' ']' sub_2_FuncFParam
    ;

sub_2_FuncFParam
    : /* empty */
    | '[' Exp ']'
    | sub_2_FuncFParam '[' Exp ']'
    ;

Block
    : '{' '}'
    | '{' BlockItems '}'
    ;

BlockItems
    : BlockItems BlockItem
    | BlockItem
    ;

BlockItem
    : Decl
    | Stmt
    ;

Stmt
    : LVal '=' Exp ';'
    | ';'
    | Exp ';'
    | Block
    | IF '(' Cond ')' Stmt ELSE Stmt
    | IF '(' Cond ')' Stmt
    | WHILE '(' Cond ')' Stmt
    | BREAK ';'
    | CONTINUE ';'
    | RETURN Exp ';'
    | RETURN ';'
    ;

Exp
    : AddExp
    ;

Cond
    : LOrExp
    ;

LVal
    : Ident LValArrayPart
    ;

LValArrayPart
    : /* empty */
    | '[' Exp ']'
    | LValArrayPart '[' Exp ']'
    ;

PrimaryExp
    : '(' Exp ')'
    | LVal
    | Number
    ;

Number
    : IntConst
    | floatConst
    ;

UnaryExp
    : PrimaryExp
    | Ident '(' ')'
    | Ident '(' FuncRParams ')'
    | UnaryOp UnaryExp
    ;

UnaryOp
    : ADD
    | SUB
    | NOT
    ;

FuncRParams
    : Exp
    | FuncRParams ',' Exp
    ;

MulExp
    : UnaryExp
    | MulExp MUL UnaryExp
    | MulExp DIV UnaryExp
    | MulExp MOD UnaryExp
    ;

AddExp
    : MulExp
    | AddExp ADD MulExp
    | AddExp SUB MulExp
    ;

RelExp
    : AddExp
    | RelExp LT AddExp
    | RelExp LE AddExp
    | RelExp GT AddExp
    | RelExp GE AddExp
    ;

EqExp
    : RelExp
    | EqExp EQ RelExp
    | EqExp NE RelExp
    ;

LAndExp
    : EqExp
    | LAndExp AND EqExp
    ;

LOrExp
    : LAndExp
    | LOrExp OR LAndExp
    ;

ConstExp
    : AddExp
    ;

%%

void yyerror(char const *s){
	fprintf (stderr, "%s/n", s);
} 