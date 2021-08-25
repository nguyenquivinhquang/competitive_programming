#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define int ll
const int N = 100009;
int n, a[N];
void solve() {
    int res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], res = max(res, a[i]);
    map<int,int> cur; // gcd, length;

    for (int i = 1; i <= n; i++) {
        map<int,int> temp;
        for (auto v : cur) {
            int gcd = __gcd(v.first, a[i]);
            res = max(res, gcd * (v.second + 1));
            // if (res == 120) cout << i << " " << v.second << " " << v.first << "\n";
            temp[gcd] = max(temp[gcd], cur[v.first] + 1);
        }
        cur.clear(); cur = temp;
        if (cur[a[i]] == 0) cur[a[i]] = 1;
    }
    cout << res << endl;
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int testcase; cin >> testcase;
    while (testcase--) solve();
}
