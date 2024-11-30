%{
    #include <stdio.h>
    #include "y.tab.h"
%}

%option yylineno

TYPE        int|float|void
CONST       const
RETURN      return
IF          if
ELSE        else
WHILE       while
BREAK       break
CONTINUE    continue
PLUS        \+
MINUS       -
INT         [1-9]+[0-9]*|0|0[xX][0-9a-fA-F]+|0[0-7]+
FLOAT       [0-9]+\.[0-9]*  
ID          [a-z_A-Z][a-zA-Z_0-9]*
SPACE       [ \t\r]*
EOL         \n
SEMI        ;
COMMA       ,
ASSIGN      =
RELOP       >|<|>=|<=|==|!=
STAR        \*
DIV         \/
AND         &&
OR          \|\|
NOT         !
LP          \(
RP          \)
LB          \[
RB          \]
LC          \{
RC          \}

%%

{SPACE}    { /* 忽略空白字符 */ }
{EOL}      { /* 忽略换行符 */ }

"//".* { }

"/*"([^\*]|(\*)*[^\*/])*(\*)*"*/" { }

{SEMI}     { return SEMICN; }
{COMMA}    { return COMMA; }
{ASSIGN}   { return ASSIGN; }
{RELOP}    { return RELOP; }
{STAR}     { return MUL; }
{DIV}      { return DIV; }
{AND}      { return AND; }
{OR}       { return OR; }
{NOT}      { return NOT; }
{LP}       { return LP; }
{RP}       { return RP; }
{LB}       { return LB; }
{RB}       { return RB; }
{LC}       { return LC; }
{RC}       { return RC; }
{TYPE}     { return TYPE; }
{RETURN}   { return RETURN; }
{BREAK}    { return BREAK; }
{CONTINUE} { return CONTINUE; }
{IF}       { return IF; }
{ELSE}     { return ELSE; }
{WHILE}    { return WHILE; }
{PLUS}     { return PLUS; }
{MINUS}    { return MINUS; }
{CONST}    { return CONST; }

{INT}  {
        int value;
        if (yytext[0] == '0' && (yytext[1] == 'x' || yytext[1] == 'X'))
            sscanf(yytext, "%x", &value);
        else if (yytext[0] == '0')
            sscanf(yytext, "%o", &value);
        else
            sscanf(yytext, "%d", &value);
        return INT_LIT;
    }

{FLOAT}    { return FLOAT_LIT; }
{ID}       { return ID; }
.          { printf("Error type A at Line %d: Invalid characters \'%s\'\n", yylineno, yytext); }

%%

int yywrap(void) {
    return 1;
}

