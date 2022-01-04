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
    map<int,int> total;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    map<int,int> cur; // gcd, length;

    for (int i = 1; i <= n; i++) {
        map<int,int> temp;
        for (auto v : cur) {
            int gcd = __gcd(v.first, a[i]);
            // total[gcd] = 1;
            // res = max(res, gcd * (v.second + 1));
            // if (res == 120) cout << i << " " << v.second << " " << v.first << "\n";
            temp[gcd] = 1;
        }
        cur.clear(); cur = temp;
        cur[a[i]] = 1;
        for (auto v: cur) total[v.first] = 1;
    }
    cout << total.size() << endl;
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int testcase=  1; 
    while (testcase--) solve();
}