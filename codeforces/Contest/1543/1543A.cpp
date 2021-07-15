#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

void solve() {
    ll a, b;
    cin >> a >> b;
    ll t = abs(a- b);
    if (t == 0) {
        cout << "0 0 \n";
        return;
    }
    if (a > b) swap(a, b);
    ll x = (b / t) + 1;
    ll res = t * x - b;

    x--;
    ll temp = b - t * x;
    if (a - temp >= 0) res = min(res, temp );
    cout << t << " " << res << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin  >> testcase;
    while (testcase--) solve();
}
