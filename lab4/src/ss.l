%{
#include <stdio.h>
%}

%option yylineno

TYPE int|float|void
RETURN return
IF if
ELSE else
WHILE while
PLUS \+
MINUS -
INTEGER [1-9]+[0-9]*|0|0[xX][0-9a-fA-F]+|0[0-7]+
FLOAT   [0-9]+\.[0-9]*  
ID [a-z_A-Z][a-zA-Z_0-9]*
SPACE [ \t\r]*
EOL \n
SEMI ;
COMMA ,
ASSIGNOP =
RELOP >|<|>=|<=|==|!=
STAR \*
DIV \/
AND &&
OR \|\|
DOT \.
NOT !
LP \(
RP \)
LB \[
RB \]
LC \{
RC \}
ERROR .

%%

{SPACE}    { /* 忽略空白字符 */ }
{EOL}      { /* 忽略换行符 */ }

"//"  {
      char c = input(); 
      while (c != '\n') 
      c = input(); 
    }

"/*"  {
      char c = input(); 
      while (c != '*' || (c = input()) != '/') 
      c = input(); 
    }

{SEMI}     { printf("SEMI: %s\n", yytext); }
{COMMA}    { printf("COMMA: %s\n", yytext); }
{ASSIGNOP} { printf("ASSIGNOP: %s\n", yytext); }
{RELOP}    { printf("RELOP: %s\n", yytext); }
{STAR}     { printf("STAR: %s\n", yytext); }
{DIV}      { printf("DIV: %s\n", yytext); }
{AND}      { printf("AND: %s\n", yytext); }
{OR}       { printf("OR: %s\n", yytext); }
{DOT}      { printf("DOT: %s\n", yytext); }
{NOT}      { printf("NOT: %s\n", yytext); }
{LP}       { printf("LP: %s\n", yytext); }
{RP}       { printf("RP: %s\n", yytext); }
{LB}       { printf("LB: %s\n", yytext); }
{RB}       { printf("RB: %s\n", yytext); }
{LC}       { printf("LC: %s\n", yytext); }
{RC}       { printf("RC: %s\n", yytext); }
{TYPE}     { printf("TYPE: %s\n", yytext); }
{RETURN}   { printf("RETURN: %s\n", yytext); }
{IF}       { printf("IF: %s\n", yytext); }
{ELSE}     { printf("ELSE: %s\n", yytext); }
{WHILE}    { printf("WHILE: %s\n", yytext); }
{PLUS}     { printf("PLUS: %s\n", yytext); }
{MINUS}    { printf("MINUS: %s\n", yytext); }

{INTEGER}  {
        int value;
        if (yytext[0] == '0' && (yytext[1] == 'x' || yytext[1] == 'X'))
            sscanf(yytext, "%x", &value);
        else if (yytext[0] == '0')
            sscanf(yytext, "%o", &value);
        else
            sscanf(yytext, "%d", &value);
        printf("INTEGER: %d\n", value);
    }

{FLOAT}    { printf("FLOAT: %s\n", yytext); }
{ID}       { printf("ID: %s\n", yytext); }
{ERROR}    { printf("Error type A at Line %d: Invalid characters \'%s\'\n", yylineno, yytext); }

%%

int main(int argc, char** argv){
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("fopen");
        return 1;
    }

    YY_BUFFER_STATE bp = yy_create_buffer(file, YY_BUF_SIZE);
    yy_switch_to_buffer(bp);
    yylex();
    yy_delete_buffer(bp);

    fclose(file);
    return 0;  
}

int yywrap(void) {
    return 1;
}

