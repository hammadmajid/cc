%{
#include <stdio.h>
%}

NUMBER      [0-9]+
ID          [a-zA-Z_][a-zA-Z0-9_]*
STRING      \"([^\"\n]*)\"
COMMENT     \#.*

%%

{NUMBER}    { printf("Number: %s\n", yytext); }

{STRING}    { printf("Text String: %s\n", yytext); }

{COMMENT}   { printf("Comment: %s\n", yytext); }

{ID}        { printf("Identifier/Command: %s\n", yytext); }

[ \t\n,]+   { /* ignore separators */ }

.           { /* ignore other characters */ }

%%

int main()
{
    FILE *file = fopen("./a1/input_data.hammad", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    yyin = file;
    yylex();
    fclose(file);
    return 0;
}

int yywrap()
{
    return 1;
}
