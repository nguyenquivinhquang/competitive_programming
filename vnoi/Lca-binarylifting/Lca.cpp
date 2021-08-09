//https://www.spoj.com/problems/LCA/
#include <bits/stdc++.h>

using namespace std;
const int N = 10005;

int level[N], dp[N][20], lgn, n;
vector<int> vertice[N];
void dfs(int u, int preU) {
    level[u] = level[preU] + 1;
    dp[u][0] = preU;
    for (int i = 1; i < lgn; i++)
        dp[u][i] = dp[dp[u][i - 1]][i - 1];
    for (auto v : vertice[u])
        dfs(v, u);
}
int lca(int u, int v) {
    if (level[u] < level[v])
        swap(u, v);
    unsigned int diff = level[u] - level[v];
    for (int i = lgn; i >= 0; i--)
        if (1 << i & diff)
            u = dp[u][i];
    if (u == v) return u;
    for (int i = lgn; i >= 0; i--) {
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return dp[u][0];
}
void input() {
    int m, u, v;
    cin >> n;
    lgn = ceil(log2(n));
    for (int i = 1; i <= n; i++) {
        cin >> m;
        vertice[i].clear();
        while (m--) {
            cin >> u;
            vertice[i].push_back(u);
        }
    }
}
void solve() {
    dfs(1, 1);
    int u, v, q;
    cin >> q;
    while (q--) {
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    int testcase;
    cin >> testcase;
    for (int i = 1; i <= testcase; i++) {
        memset(dp, 0, sizeof(dp));
        memset(level, 0, sizeof(level));
        
        cout << "Case " << i << ":\n";
        input();
        solve();
    }
}