#include <bits/stdc++.h>
#define int ll 
#define ll long long
#define pp pair<int, int>

const int N = 1005;

using namespace std;
int a[N], n, b[N];
void solve() {
    cin >> n;
    int cur = 1e12;
    for (int i = 1; i <= n; i++) cin >> a[i], cur = min(cur, a[i]);
    int res = 1e12; bool fee = false;
    while (fee == false) {
        fee = true;
        for (int i = 1; i <= n; i++) {
            if (a[i] >  (a[i] & cur)) {
                a[i] &= cur;
                fee = false;
            }
            res = min(res, a[i]);
        }
        cur = res;
    }
    for (int i = 1; i <= n; i++) res = max(res, a[i]);
    cout << res << "\n";

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) solve();
}
