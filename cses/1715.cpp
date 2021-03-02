#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000009;
const int m = 1e9 + 7;
using namespace std;

int modInverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        int q = a / m;
        int t = m;

        m = a % m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    string s;
    cin >> s;
    ll fac[N];
    int trace[100];
    fac[1] = fac[0] = 1;
    for (int i = 2; i < N; i++)
        fac[i] = (fac[i - 1] * i) % m;
    memset(trace, 0, sizeof(trace));
    for (auto c : s)
        trace[c - 'a']++;
    ll t = 1;
    for (int i = 0; i <= 50; i++)
        t = (t * fac[trace[i]]) % m;
    cout << (fac[s.length()] * modInverse(t, m)) % m;
}