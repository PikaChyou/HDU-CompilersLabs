%{
    #include <stdio.h>
    #include <stdbool.h>
    #include "y.tab.h"

    bool error_flag = false;
%}

%option yylineno
%option header-file="lex.yy.h"

INT         int
FLOAT       float
VOID        void
CONST       const
RETURN      return
IF          if
ELSE        else
WHILE       while
BREAK       break
CONTINUE    continue
PLUS        \+
MINUS       -
INT_LIT     [1-9]+[0-9]*|0|0[xX][0-9a-zA-Z]+|0[0-9]+
FLOAT_LIT   [0-9]+\.[0-9]*  
ID          [a-z_A-Z][a-zA-Z_0-9]*
SPACE       [ \t\r]*
EOL         \n
SEMICN      ;
COMMA       ,
ASSIGN      =
EQ          ==
NE          !=
LT          <
LE          <=
GT          >
GE          >=
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

{INT}      { return INT; }
{FLOAT}    { return FLOAT; }
{VOID}     { return VOID; }
{SEMICN}   { return SEMICN; }
{COMMA}    { return COMMA; }
{ASSIGN}   { return ASSIGN; }
{EQ}       { return EQ; }
{NE}       { return NE; }
{LT}       { return LT; }
{LE}       { return LE; }
{GT}       { return GT; }
{GE}       { return GE; }
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
{RETURN}   { return RETURN; }
{BREAK}    { return BREAK; }
{CONTINUE} { return CONTINUE; }
{IF}       { return IF; }
{ELSE}     { return ELSE; }
{WHILE}    { return WHILE; }
{PLUS}     { return PLUS; }
{MINUS}    { return MINUS; }
{CONST}    { return CONST; }

{INT_LIT}  {
        int value;
        if (yytext[0] == '0' && (yytext[1] == 'x' || yytext[1] == 'X'))
        {
            for (int i = 2; yytext[i] != '\0'; i++) {
                if (yytext[i] < '0' || (yytext[i] > '9' && yytext[i] < 'A') || (yytext[i] > 'F' && yytext[i] < 'a') || yytext[i] > 'f') 
                {
                    fprintf(stderr, "Error type A at Line %d: Invalid hexadecimal number: %s\n", yylineno, yytext);
                    error_flag = true;
                }
            }
            sscanf(yytext, "%x", &value);
        }
        else if (yytext[0] == '0')
        {
            for (int i = 1; yytext[i] != '\0'; i++) {
                if (yytext[i] < '0' || yytext[i] > '7')
                {
                    fprintf(stderr, "Error type A at Line %d: Invalid octal number: %s\n", yylineno, yytext);
                    error_flag = true;    
                }
            }
            sscanf(yytext, "%o", &value);
        }
        else
            sscanf(yytext, "%d", &value);
        yylval.int_val = value;
        return INT_LIT;
    }

{FLOAT_LIT}  { yylval.float_val = atof(yytext); return FLOAT_LIT; }
{ID}       { yylval.str_val = strdup(yytext); return ID; }
.          { printf("Error type A at Line %d: Invalid characters \'%s\'\n", yylineno, yytext); error_flag = true; }

%%

int yywrap(void) {
    return 1;
}

