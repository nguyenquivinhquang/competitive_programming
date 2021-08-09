#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
void displayBits(unsigned value) {
    unsigned c, displayMask = 1 << 31;
    for (int i = 1; i <= 32; i++) {
        putchar(value & displayMask ? '1' : '0');
        value <<= 1;
        if (i % 8 == 0)
            cout << ' ';
    }
}
int main() {
    int testcase;
    displayBits(12);
}