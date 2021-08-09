#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 100009;

using namespace std;
vector<int> vertice[N];
int n;
ll res = 0;
ll dfs(int u, int preU) {
    ll subTree = 1;
    for (auto v : vertice[u]) {
        if (v == preU) continue;
        ll count = dfs(v, u);
        subTree += count;
        if (count % 2 == 0) res++;
    }
    
    return subTree;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        vertice[u].push_back(v);
        vertice[v].push_back(u);
    }
    if (n % 2 == 1) {
        cout << -1;
        return 0;
    }
    dfs(1, 0);
    cout << res;
}
