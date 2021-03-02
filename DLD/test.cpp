#include <bits/stdc++.h>

using namespace std;
int func1(int x) {

    bitset<4> bitS(x);
    int a = bitS[3], b = bitS[2], c = bitS[1], d = bitS[0];
    return ((!a) && (!c))   || (!b && d);
}
int main() {
    for (int i = 0; i <= 15; i++) {
        cout << i << " " << func1(i) << "\n";
    }
}
