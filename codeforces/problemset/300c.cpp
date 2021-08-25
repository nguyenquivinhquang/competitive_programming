#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>
#define int long long
const int N = 1000009;
const int m = 1e9 + 7;
using namespace std;
ll Pow(ll x, ll k, ll m) {
    if (k == 1) return x;
    if (k == 0) return 1;
    ll t = Pow(x, k / 2, m);
    t = (t * t) % m;
    if (k % 2 == 0)
        return t;
    else
        return (t * x) % m;
}
int modInverse(int a, int m) {
   return Pow(a, m - 2, m);
}
ll res = 0, a, b, n;
bool check(ll sum, ll a, ll b) {
    while (sum) {
        if (sum % 10 != a && sum % 10 != b) return false;
        sum /= 10;
    }
    return true;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    ll fac[N];
    cin >> a >> b >> n;
    fac[1] = fac[0] = 1;
    for (int i = 2; i < N; i++)
        fac[i] = (fac[i - 1] * i) % m;

    for (int i = 0; i <= n; i++) {
        ll sum = a * i + (n - i) * b;
        if (check(sum, a, b) ==  false ) continue;
        ll t1 = fac[n], t2 = fac[i] * (fac[n - i]) % m;
        res += t1 * modInverse(t2, m) % m;
        res %= m;
    }
    cout << res;
}
