#include <bits/stdc++.h>
#define int ll
#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

vector<int> fac;

int n, res = 1e9;
void chec(int h, int w, int d) {
    int area = 2 * (h * w + d * w + h * d);
    if (area < res) res = area;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= cbrt(n) + 10; i++) {
        for (int j = i; j <= cbrt(n) + 10; j++) {
            int rem = n / (i * j);
            if (rem * i * j != n) continue;
            chec(i, j, rem);
        }
    }
    for (int i = 1; i <= sqrt(n) + 1; i++) {
        int rem = n / i;
        if (rem * i != n) continue;
        chec(rem, i, 1);
    }
    cout << res;
}
