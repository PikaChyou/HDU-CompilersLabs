#include "lex.yy.h"

// extern FILE *yyin;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // yyin = fopen(argv[1], "r");
    // if (!yyin)
    // {
    //     perror("fopen");
    //     return 1;
    // }

    FILE *f = fopen(argv[1], "r");
    if (!f)
    {
        perror("fopen");
        return 1;
    }

    YY_BUFFER_STATE bp = yy_create_buffer(f, YY_BUF_SIZE);
    yy_switch_to_buffer(bp);
    yylex();
    yy_delete_buffer(bp);

    fclose(f);
    return 0;
}
