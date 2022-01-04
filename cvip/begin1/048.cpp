#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, k, q;
int a[1000009];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while(q--) {
        cin >> k;
        ll res = 0;
        for (int i = 1; i*k <= n; i++)
            res += a[i*k];
        cout << res << "\n";
    }
}
