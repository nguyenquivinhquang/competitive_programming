#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    if (a == 1) {
        if ((n - 1) % b == 0) cout << "Yes\n";
        else  cout << "No\n";
        return;
    }
    ll s = 1;
    while (s <= n) {
        if ((n - s) % b == 0) {
            cout << "Yes\n";
            return;
        }
        s = s * a;
    }
    cout << "No\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int c = 0, x = 1;

    int testcase;
    cin >> testcase;
    while (testcase--) {
        solve();
    }
}