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
    int min_m, max_m, n, cur = 0;
    cin >> n;
    min_m = 0, max_m = 0;
    for (int i = 1; i <= n; i++) {
        int d; cin >> d;
        int left = cur - d, right = cur + d;
        if (left >= min_m && right <= max_m) {
            int d_l = abs(min_m - left), d_r = abs(max_m - right);
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
