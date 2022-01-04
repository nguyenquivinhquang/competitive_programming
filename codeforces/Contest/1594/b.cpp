#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;
const int Mod = 1e9 + 7;
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
    long long n,k,res = 0;
    cin >> n >> k;
    for (int i = 0; i < 30; i++) {
        if (k & (1 << i))    res = (res + Pow(n, i, Mod)) %  Mod;
    }
    cout << res << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
