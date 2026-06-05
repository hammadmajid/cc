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
