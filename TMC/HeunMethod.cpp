#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

double f(double x, double y) {
    return 4 * exp(0.8 * x) - 0.5 *y;
}
void test() {
    double y = 5, ypre = 2, x = 0;
    double h = 1;
    for (int i = 1; i <= 15; i++) {
        y = 2 + (f(0, 2) + f(1, y)) / 2.0;
        cout << y << endl;
    }
    
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    test();
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/