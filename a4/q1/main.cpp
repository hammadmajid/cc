#include <iostream>
#include <cstring>

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
    strcpy(symbolTable[symbolCount].name, name);
    strcpy(symbolTable[symbolCount].type, type);
    symbolCount++;
}

void func_name(const char name[]) {
    if (lookupFunction(name) != -1) {
        cout << "Error: Function already declared" << endl;
    }
}

void FuncDecl(const char name[]) {
    if (lookupFunction(name) == -1) {
        insertFunction(name, "FUNCTION");
        cout << "Inserted: " << name << " FUNCTION" << endl;
    } else {
        cout << "Error: Function already declared" << endl;
    }
}

int main() {
    FuncDecl("add");
    FuncDecl("print");
    FuncDecl("add");
    return 0;
}
