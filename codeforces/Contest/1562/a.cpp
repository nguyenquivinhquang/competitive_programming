#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1000;

void solve() {
    ll n, l; cin >> l >> n;
    ll res = n % l;
    if ((n + 1) / 2 >= l) {
        int mid = (n + 1) / 2;
        res = max(res, n % mid);
        if (mid + 1 <= n) res = max(res, n % (mid + 1));
    }
    cout << res << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    while (testcase--) solve();
}
