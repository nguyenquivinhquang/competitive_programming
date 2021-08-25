#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1000;
void solve() {
    ll a, b, c, n;
    cin >> a >> b >> c; if (a > b ) swap(a, b);
    n = abs(b - a);
    ll d;
    if (n >= c) d = n + c; else d =  c - n;
    // if (d < c) swap(d, c);
    if (d == a || d == b || d <= 0 || d > 2 * n || c > 2 * n ) d = -1;
   
    if ( n < a) d = -1;
    cout <<d <<  "\n";
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // cin.exceptions(cin.failbit);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        solve();
    }
}
