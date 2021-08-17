#include <bits/stdc++.h>

#define int long long
#define ll long long
#define pp pair<int, int>

const int N = 6000;
const int M = 998244353;
using namespace std;
int n, m, k;
vector<int> vertice[N];
int dp[N], dp2[N];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        vertice[u].push_back(v);
        vertice[v].push_back(u);
    }
    dp[1] = 1;

    for (int i = 1; i <= k; i++) {
        int total = 0;
        for (int j = 1; j <= n; j++) total = total + dp[j];

        for (int j = 1; j <= n; j++) {
            dp2[j] = total - dp[j]; 
            for (auto v : vertice[j]) dp2[j] = (dp2[j] -  dp[v]);
            dp2[j] %= M;
        }
        for (int j = 1; j <= n; j++) dp[j] = dp2[j];
    }
    // for (int i = 1; i <= n; i++) cerr << dp[i] << " ";
    cout << dp[1];
}
