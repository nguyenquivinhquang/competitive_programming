#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
double computeF1(double x) {
    return 4 - 3.6 * x + 3.6 * x * x - 1.2 * x * x * x;
}
double computeF2(double x) {
    return -3.6 + 7.2 * x - 3.6 * x * x;
}
double computeF(double x) {
    return 4 * x - 1.8 * x * x + 1.2 * x * x * x - 0.3 * x * x * x * x;
}
double err(double x, double prex) {
    return (abs(x - prex) / x) * 100;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    double prex = 100, x = 10;
    int iterator = 1;
    while (1) {
        double f0 = computeF(x), f1 = computeF1(x), f2 = computeF2(x);
        x = prex - f1 / f2;
        cout << "Iterator : " << iterator << " X is: " << x << " F is " << f0
             << " First derivative: " << f1 << " Second Derivative: " << f2 << "\n";
        if (err(x, prex) < 0.5 || iterator > 50)
            break;
        prex = x;
        iterator++;
    }
    cout << "X is: " << x << " fx is " << computeF(x);
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/