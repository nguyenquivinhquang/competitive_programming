#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
const int N = 100009;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, a[N];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int res =0 ;
    if (n % 2 == 1) n--;
    for (int i = 1; i <= n; i+=2) {
        int prefix_sum = 0, _min = 0;
        for (int j = i + 1; j <= n; j++) {
            if (j % 2 == 0 ) {
                int open_b = max(-_min, 1ll), close_b = max(prefix_sum - _min, 1ll);
                if (open_b <= a[i] && close_b <= a[j]) res += min(-open_b + a[i], - close_b + a[j]) + 1;
            }
            if (j % 2 == 0) prefix_sum -= a[j]; 
            else prefix_sum += a[j];
            _min = min(_min, prefix_sum);
        }
        
    }
    cout << res << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    // cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}