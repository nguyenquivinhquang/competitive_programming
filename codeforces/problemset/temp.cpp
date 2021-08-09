#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 300000;

using namespace std;

vector<int> vertice[N];
set<int> count_color[N];
int color[N], n, res[N];

void dfs(int u, int preU) {
    count_color[u].insert(color[u]);
    for (auto v : vertice[u]) {
        if (v == preU) continue;
        dfs(v, u);
        if (count_color[v].size() > count_color[u].size()) swap(count_color[u], count_color[v]);
        for (auto temp : count_color[v])
        count_color[u].insert(temp);
        count_color[v].clear();
    } 
    res[u] = count_color[u].size();
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vertice[x].push_back(y);
        vertice[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) cin >> color[i];
    dfs(1, 0);
    for (int i = 1; i <= n; i++) cout << res[i] << " ";
}
