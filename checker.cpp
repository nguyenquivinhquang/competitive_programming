#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100000, "n");
    inf.readSpace();
    int q = inf.readInt(1, 100000, "q");
    inf.readEoln();
    
    for (int i = 0; i < n; i++) {
        int x = inf.readInt(0, n, "x");
        inf.readSpace();
    }
    inf.readEof();

    for (int i = 0; i < q; i++) {
        int l = inf.readInt(0, n, "l");
        inf.readSpace();
        int r = inf.readInt(0, n, "r");
        inf.readEof();
        ensuref(l <= r, "l greater than r");
    }
    inf.readEof();
}