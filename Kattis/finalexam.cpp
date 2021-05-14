#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<char> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    int ans = 0;
    for (int i = 0; i+1 < n; i++) {
        if (c[i] == c[i+1]) ans++;
    }
    cout << ans << '\n';

    return 0;
}