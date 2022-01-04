#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;
#define M  1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int f[N];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    f[1] = 1; f[2] = 1;
    for (int i = 3; i <= 88; i++) {
        f[i] = f[i-2] + f[i-1];
    }
    int q; cin >> q;
    while(q--) {
        int n, k; cin >> n >> k;
        if (n > 88 || f[n] > k) cout << "no\n";
        else cout << "yes\n";
    }
}
