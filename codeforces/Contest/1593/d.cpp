#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;
const int Lim = 4;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, a[N];

void solve() {
    int MIN = 1e8;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], MIN = min(MIN, a[i]);
    for (int i = 1; i <= n; i++) a[i] -= MIN;
    int gcd = a[1];
    for (int i = 2; i <= n; i++) gcd = __gcd(gcd, a[i]);
    if (gcd == 0) gcd = -1;
    cout << gcd << "\n";


}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
