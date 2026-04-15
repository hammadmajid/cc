%{
#include "tokens.h"

YYSTYPE yylval;
%}

%%

[0-9]+\.[0-9]*      { yylval.floatval = atof(yytext); return FLOAT_CONST; }
\.[0-9]+            { yylval.floatval = atof(yytext); return FLOAT_CONST; }
[0-9]+              { yylval.intval = atoi(yytext); return INTEGER_CONST; }
[ \t]+              ;
\n                  { return NEWLINE; }
.                   { return UNKNOWN; }

%%

int yywrap() {
    return 1;
}
