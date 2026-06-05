%{
#include "q1.tab.h"
#include <string.h>
#include <stdlib.h>

void assign_string(char **dest, const char *src) {
    *dest = (char *)malloc(strlen(src) + 1);
    strcpy(*dest, src);
}
%}

%%

"function"              { return FUNCTION; }
[a-zA-Z_][a-zA-Z0-9_]* { 
                            assign_string((char **)&yylval.sval, yytext);
                            return IDENTIFIER; 
                        }
";"                     { return SEMICOLON; }
[ \t\n]                 { /* ignore whitespace */ }
.                       { /* ignore unknown characters */ }

%%

int yywrap() {
    return 1;
}
