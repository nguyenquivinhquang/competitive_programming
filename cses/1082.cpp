#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;
const int m = 1e9 + 7;
using namespace std;
ll fee[N + 3], prefix[N + 3];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    ll n, res = 0;
    cin >> n;
    res = (n % m) * ((n + 1) % m) / 2 + n - 1;
    res %= m;
    for (ll i = 2; i <= sqrt(n); i++) {
        ll t = n / i - 1;
        if (n % i == 0) res += n / i;
        res = (res + (t * i) % m) % m;
    }
    cout << res << endl;
}
/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/