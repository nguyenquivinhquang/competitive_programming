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
    ll fac[N];
    int testcase;
    fac[1] = 1;
    for (int i = 2; i < N; i++)
        fac[i] = (fac[i - 1] * i) % m;
    cin >> testcase;
    while (testcase--) {
        ll a, b;
        cin >> a >> b;
        ll t1 = fac[a], t2 = fac[b] * (fac[a - b]) % m;
        ll res = t1 * modInverse(t2, m) % m;
        cout << res << "\n";
    }

}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/