#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>
#define int long long
const int N = 100009;

using namespace std;
int n, m, coints[N], k = 0, group[N], val[N], dp[N];
vector<int> vertice[N], rev[N], st, component, nvertice[N];  // nvertice -> new graph
vector<bool> fee;
void dfs1(int u) {
    fee[u] = true;
    for (auto v : vertice[u]) {
        if (fee[v]) continue;
        dfs1(v);
    }
    st.push_back(u);
}
void dfs2(int u) {
    fee[u] = true;
    component.push_back(u);
    for (auto v : rev[u]) {
        if (fee[v]) continue;
        dfs2(v);
    }
}
void Build_new_Graph() {
    fee.assign(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (fee[i]) continue;
        dfs1(i);
    }
    fee.assign(n + 1, false);
    reverse(st.begin(), st.end());
    for (auto u : st) {
        if (fee[u]) continue;
        dfs2(u);
        k++;
        val[k] = 0;
        for (auto v : component) {
            group[v] = k;
            val[k] += coints[v];
        }
        component.clear();
    }
    for (int i = 1; i <= n; i++)
        for (auto v : vertice[i]) {
            if (group[i] == group[v]) continue;
            nvertice[group[i]].push_back(group[v]);
        }
}
void dfs(int u) {
    fee[u] = true;
    for (auto v : nvertice[u]) {
        dp[u] = max(dp[u], dp[v]);
        if (fee[v] == true) continue;
        dfs(v);
        dp[u] = max(dp[u], dp[v]);
    }
    dp[u] += val[u];
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int x, y;
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> coints[i];
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        vertice[x].push_back(y);
        rev[y].push_back(x);
    }
    Build_new_Graph();
    fee.assign(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (fee[i]) continue;
        dfs(i);
    }
    int res = 0;
    for (int i = 1; i <= k; i++)
        res = max(res, dp[i]);
    cout << res;
}
