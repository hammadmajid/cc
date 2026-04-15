#ifndef TOKENS_H
#define TOKENS_H

#include <string.h>
#include <stdlib.h>

/* Token types */
#define INTEGER_CONST 1
#define FLOAT_CONST 2
#define NEWLINE 3
#define UNKNOWN 4

/* Union for yylval */
typedef union {
    int intval;
    double floatval;
} YYSTYPE;

extern YYSTYPE yylval;
extern char *yytext;

#endif /* TOKENS_H */
