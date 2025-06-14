#include "header.h"
void printPascal(int n) {
    for (int line = 1; line <= n; line++) {
        int C = 1; // used to represent C(line, i)
        for (int i = 1; i <= line; i++) {
            cout << C << " ";
            C = C * (line - i) / i;
        }
        cout << "\n";
    }
}