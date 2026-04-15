#include <stdio.h>
#include "tokens.h"

extern FILE *yyin;
extern int yylex();

const char *token_name(int token) {
    switch(token) {
        case INTEGER_CONST: return "INTEGER_CONST";
        case FLOAT_CONST: return "FLOAT_CONST";
        case NEWLINE: return "NEWLINE";
        case UNKNOWN: return "UNKNOWN";
        default: return "UNKNOWN";
    }
}

int main() {
    int token;
    
    printf("Lexical Analysis for Numeric Constants\n");
    printf("======================================\n");
    printf("Enter numeric values (integers and floats). Press Ctrl+D to exit.\n\n");
    
    while ((token = yylex())) {
        if (token == NEWLINE) {
            printf("\n");
        } else if (token == INTEGER_CONST) {
            printf("[%s] value=%d\n", token_name(token), yylval.intval);
        } else if (token == FLOAT_CONST) {
            printf("[%s] value=%f\n", token_name(token), yylval.floatval);
        } else if (token == UNKNOWN) {
            printf("[%s] char='%s'\n", token_name(token), yytext);
        }
    }
    
    printf("\nEnd of input.\n");
    return 0;
}
