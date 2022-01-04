#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vector<int> phi(1e6);
void phi_1_to_n(int n) {
    n = 1e6;
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
              phi[j] -= phi[i];
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    phi_1_to_n(1e6);
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        cout << phi[x] << "\n";
    }
}
