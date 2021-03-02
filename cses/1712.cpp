#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;
const int M = 1e9 + 7;
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

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    ll a, b, c;
    cin >> testcase;
    while (testcase--) {
        cin >> a >> b >> c;
        ll t = Pow(b, c, M - 1);
        cout << Pow(a, t, M) << "\n";
    }
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/