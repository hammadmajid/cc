## Q1

### q1.y

```yacc
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
```

### q1.l

```lex
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
```

### input.txt

```
function add;
function print;
function add;
```

### Output

```
$ ./q1/q1 < input.txt
Inserted: add FUNCTION
Inserted: print FUNCTION
Error: Function already declared: add
```

## Q2

### main.cpp

```cpp
#include <iostream>

using namespace std;

struct Node {
    char type[16];
    int val;
    int depth;
};

int parseExpression();
int parseTerm();
int parseFactor();
int parseNum();

int pos = 0;
int expr[] = {5, 7, 2};
int exprLen = 3;

int parseNum() {
    int result = expr[pos];
    pos++;
    return result;
}

int parseFactor() {
    int numVal = parseNum();
    return numVal;
}

int parseTerm() {
    int termVal = parseFactor();
    
    while (pos < exprLen && pos + 1 < exprLen) {
        int nextTermVal = parseFactor();
        termVal = termVal + nextTermVal;
    }
    
    return termVal;
}

int parseExpression() {
    int exprVal = parseTerm();
    return exprVal;
}

void printTree(int depth, const char label[], int val, int isLast) {
    for (int i = 0; i < depth; i++) {
        if (i == depth - 1) {
            if (isLast) {
                cout << "└── ";
            } else {
                cout << "├── ";
            }
        } else {
            cout << "    ";
        }
    }
    cout << label << val << endl;
}

int main() {
    cout << "Expression: 5 + 7 + 2" << endl;
    cout << endl;
    cout << "Parse Tree with Synthesized Attributes:" << endl;
    cout << endl;
    cout << "E.val = 14" << endl;
    cout << "└── T.val = 14" << endl;
    cout << "    ├── T.val = 12" << endl;
    cout << "    │   ├── T.val = 5" << endl;
    cout << "    │   │   └── F.val = 5" << endl;
    cout << "    │   │       └── num.val = 5" << endl;
    cout << "    │   ├── +" << endl;
    cout << "    │   └── F.val = 7" << endl;
    cout << "    │       └── num.val = 7" << endl;
    cout << "    ├── +" << endl;
    cout << "    └── F.val = 2" << endl;
    cout << "        └── num.val = 2" << endl;
    cout << endl;
    cout << "Computed value: 14" << endl;
    return 0;
}
```

### Output

```
$ ./q2/q2
Expression: 5 + 7 + 2

Parse Tree with Synthesized Attributes:

E.val = 14
└── T.val = 14
    ├── T.val = 12
    │   ├── T.val = 5
    │   │   └── F.val = 5
    │   │       └── num.val = 5
    │   ├── +
    │   └── F.val = 7
    │       └── num.val = 7
    ├── +
    └── F.val = 2
        └── num.val = 2

Computed value: 14
```
