#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 300009;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, q;
int a[N], prefix[N];
void solve() {
    cin >> n >> q;
    char c;
    for (int i = 1 ; i <= n; i++) {
        cin >> c;
        if (c == '+') a[i] = 1;
        else a[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        prefix[i] = a[i];
        if (i == 1) continue;
        if (i % 2 == 0) prefix[i] = prefix[i-1] - prefix[i];
        else prefix[i] += prefix[i- 1];
    }
    for (int i = 1; i <= q; i ++ ) {
        int l, r;
        cin >> l >> r;
        int s = prefix[r] - prefix[l-1];
        if (s == 0) cout << 0;
        else if ((r - l) % 2 ) cout << 2;
        else cout << 1;
        cout << "\n";
    }
    
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase; cin >> testcase;
    while (testcase--) {
        solve();
    }
}
