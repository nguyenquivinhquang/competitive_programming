#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pp pair<int, int>

const int N = 1000001;

using namespace std;

long long n, dp[N], w[N], W, v[N], V;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin  >> n >> W;
    for (int i = 1; i <= n; i++ ){
        cin >> w[i] >> v[i];
        V += v[i];
    }
    for (int i = 1; i <= V; i++) dp[i] = 1e10;
    int res = 0;
    for (int i = 1; i <= n; i++ ) {
        for (int j = V; j >= v[i]; j--) {
            if (dp[j - v[i]] + w[i] > W) continue;
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
            res = max(res, j);
        }
    }
    cout << res;
}
