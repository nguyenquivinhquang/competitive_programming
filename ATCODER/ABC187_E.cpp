#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 200004;

using namespace std;

pp edge[N];
vector<int> vertice[N];
long long parent[N], res[N], total_sum = 0, val[N];
int n;
void dfs(int u, int preU) {
    parent[u] = preU;
    for (auto v : vertice[u]) {
        if (v == preU) continue;
        dfs(v, u);
    }
}

void dfs1(int u, ll debt) {
    debt += val[u];
    res[u] = debt + total_sum;

    for (auto v : vertice[u]) {
        if (v == parent[u]) continue;
        dfs1(v, debt);
    }
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        edge[i] = {x, y};
        vertice[x].push_back(y);
        vertice[y].push_back(x);
    }
    int q, t, idx, x;
    dfs(1, 0);
    cin >> q;
    while (q--) {
        cin >> t >> idx >> x;
        int u = edge[idx].first, v = edge[idx].second;
        if (t == 2) swap(u, v);
        if (parent[v] == u) {
            total_sum += x;
            x = -x;
            swap(u, v);
        }
        val[u] += x;
    }
    dfs1(1, 0);
    for (int i = 1; i <= n; i++)
        cout << res[i] << "\n";
}
