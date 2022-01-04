#include <bits/stdc++.h>
using namespace std;
#define int int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll Pow(ll x, ll k, ll m) {
    if (k == 1) return x;
    if (k == 0) return 1;
    ll t = Pow(x, k / 2, m);
    t = (t * t) % m;
    if (k % 2 == 0)
        return t;
    else
        return (t * x) % m;
}
void solve() {
    int res = 6, k = 1;
    cin >> k;
    ll node  = 1; 
    for (int i = 1; i <= k; i++) node *= 2;
    node -= 2;
    res = 6 * Pow(4, node, 1000000007);
    res %= 1000000007;
    cout << res;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    solve();
}
