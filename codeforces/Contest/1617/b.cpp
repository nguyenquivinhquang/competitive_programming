#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void solve() {
    int n; cin >> n;
    n--;
    for (int i = 2; i <= n; i++) {
        int rem = n - i;
        if (__gcd(rem, i) == 1) {
            cout << i << " " << rem << " " << 1 << "\n";
            return;
        }
    }
    // cout << x << " " << y << " " << 1 << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
