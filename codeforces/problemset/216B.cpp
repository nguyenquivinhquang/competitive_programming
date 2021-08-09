#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 100000;

using namespace std;

int n, m, res = 0;
int fee[N], group[N];
vector<vector<int>> vertice;
void dfs(int u, int preU) {
    fee[u] = 1;
    for (auto v : vertice[u]) {
        if (v == preU) continue;
        if (group[v] == group[u] && group[v] != -1) {
            res++;
            break;
        }
        if (fee[v] == 1) continue;
        if (group[u] == 1) group[v] = 2; else group[v] = 1;
        dfs(v, u);
    }
}
void solve() {
    cin >> n >> m;
    vertice.resize(n + 10);
    memset(fee, 0, sizeof(fee));
    memset(group, -1, sizeof(group));
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        vertice[x].push_back(y);
        vertice[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (fee[i] == 0) {
            group[i] = 1;
            dfs(i, i);
        }
    }
    res /= 2;
    if ((n - res) % 2 != 0) res ++;
    cout << res;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    solve();
}
