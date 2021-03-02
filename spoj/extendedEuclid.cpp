#include <bits/stdc++.h>

using namespace std;
int x, y, d;
void extendedEuclid(int a, int b) {
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
        return;
    }
    extendedEuclid(b, a % b);
    int temp = x;
    x = y;
    y = temp - (a / b) * y;

 }

signed main() {
    extendedEuclid(16, 10);
    cout << x  << " " << y;

}
