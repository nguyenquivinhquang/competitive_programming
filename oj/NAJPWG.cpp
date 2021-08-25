#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 100000;
ll prefix[N + 1];
#define int long long
vector<int> phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
              phi[j] -= phi[i];
    return phi;
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    vector<int> phi = phi_1_to_n(N);
    for (int i = 1; i <= N; i++) prefix[i] = prefix[i - 1] + phi[i];
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++){
        ll n; cin >> n;
        cout << "Case " << t << ": " << ((n + 1) * n) / 2 - prefix[n] << "\n";

    }
}
