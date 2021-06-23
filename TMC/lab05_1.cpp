#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
double f(double x) {
    return 4 * x - 1.8 * pow(x, 2) + 1.2 * pow(x, 3) - 0.3 * pow(x, 4);
}
void gss(double a, double b) {
    double r = (sqrt(5) - 1) / 2, eps = 0.01;
    double x1 = b - r * (b - a), x2 = a + r * (b - a);
    double f1 = f(x1), f2 = f(x2);
    while (abs(b - a) > eps) {
        // cout << x1 << " " << f1 << "\n";
        if (f1 > f2) {
            b = x2, x2 = x1, f2 = f1;
            x1 = b - r * (b - a), f1 = f(x1);
        } else {
            a = x1, x1 = x2, f1 = f2;
            x2 = a + r * (b - a), f2 = f(x2);
        }
    }
    cout << a;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    gss(2.0, 4.0);
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/