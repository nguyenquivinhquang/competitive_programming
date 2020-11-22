#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

void solve() {
    int x, y;
    cin >> x>> y;
    if (x == y) cout << x + y; else cout << 2 * max(x , y) - 1;
    cout << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) {
       solve();
    }
}
