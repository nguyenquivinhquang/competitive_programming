#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000009;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll a[N], n, k;
char sig;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (k--) {
        ll x, y;
        cin >> sig >> x >> y;
        if (sig == '+') cout << a[x] + a[y];
        else cout << a[x] * a[y];
        cout << "\n";
    }
}
