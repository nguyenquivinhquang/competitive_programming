#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // cout << a[0] << endl;
    int res = 3 * a[0];
    for (auto v : a) {
        if (res < v) v = res;
    }
    cout << res + 1 << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while(testcase--) {
        solve();
    }
 }
