%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

const int MAX_SYMBOLS = 100;
const int MAX_NAME_LEN = 64;

struct Symbol {
    char name[MAX_NAME_LEN];
    char type[MAX_NAME_LEN];
};

Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;

int lookupFunction(const char name[]) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void insertFunction(const char name[], const char type[]) {
    if (symbolCount >= MAX_SYMBOLS) {
        cerr << "Error: Symbol table full" << endl;
        return;
    }
    strcpy(symbolTable[symbolCount].name, name);
    strcpy(symbolTable[symbolCount].type, type);
    symbolCount++;
}

void FuncDecl(const char name[]) {
    if (lookupFunction(name) == -1) {
        insertFunction(name, "FUNCTION");
        cout << "Inserted: " << name << " FUNCTION" << endl;
    } else {
        cerr << "Error: Function already declared: " << name << endl;
    }
}

extern int yylex();
void yyerror(const char *s);
%}

%union {
    char *sval;
}

%token FUNCTION SEMICOLON
%token <sval> IDENTIFIER

%start program

%%

program:
    /* empty */
    | program func_declaration
    ;

func_declaration:
    FUNCTION IDENTIFIER SEMICOLON
    {
        FuncDecl($2);
        free($2);
    }
    ;

%%

void yyerror(const char *s) {
    cerr << "Parse error: " << s << endl;
}

int main() {
    return yyparse();
}
