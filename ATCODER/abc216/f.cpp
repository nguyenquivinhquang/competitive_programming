#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
const int N = 5009;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, a[N], c_l[N], c_r[N], b[N], c_ll[N], c_rr[N], m = 0;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i], m = max(m, b[i]);
    vector<int> q;
    q.push_back(0);
    a[0] = 1e9;
    for (int i = 1;i <= n; i++) {
        while (q.size() && a[q.back()] <= a[i]) q.pop_back();
        int debug;
        if (q.size() ) debug = q.back();
        if (q.size() ) c_l[i] = i - c_l[q.back()];
        q.push_back(i);
    }
    q.clear();
    q.push_back(n + 1); a[n+1] = 1e9;
    reverse(a + 1, a + 1 + n);
    for (int i = 1;i <= n; i++) {
        while (q.size() && a[q.back()] <= a[i]) q.pop_back();
        if ( q.size() ) c_r[i] = i - c_r[q.back()] ;
        q.push_back(i);
    }
    q.clear();
    q.push_back(0); b[0] = 1e9;
    reverse(c_r + 1, c_r + 1 + n);
    ll res = 0;
    reverse(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (m >  a[i]) continue;
        res +=  (c_l[i] *c_r[i]) % 998244353;
        res %= 998244353;
        
    }
    cout << res;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    solve();
    // int t; cin >>t;
    // while(t--) solve();
}