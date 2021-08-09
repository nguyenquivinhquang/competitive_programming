#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

void solve() {
    int n;
    vector<int> a;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int g = a[0];
    for (int i = 1; i < n; i++)
        g = __gcd(a[i], g);
    ll res = 0;
    for (auto x : a) {
        res += (x/g) * g;
    }
    cout << res << " " << g << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        solve();
    }
}
