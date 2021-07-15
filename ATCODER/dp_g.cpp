#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 100009;

using namespace std;
int n, m, res = 0;
int dp[N];
bool trace[N];
vector<int> vertice[N];
void dfs(int u) {
    trace[u] = true;
    for (auto v : vertice[u]) {
        if (trace[v] == false) dfs(v);
        dp[u] = max(dp[u], dp[v]);         
    }
    dp[u]++;
    res = max(res, dp[u]);
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
   
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        vertice[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        if (trace[i] == false) dfs(i);
    }
    cout << res - 1;
}
