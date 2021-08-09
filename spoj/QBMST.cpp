#include <bits/stdc++.h>
#define ll long long
#define pp pair<int, int>
using namespace std;
const int N = 10009;
int n, root[N], level[N], m;
vector<pair<ll, pp>> edge;
void makeSet() {
    for (int i = 1; i <= n; i++) {
        root[i] = i;
        level[i] = 0;
    }
}
ll findRoot(int u) {
    if (u == root[u]) return u;
    root[u] = findRoot(root[u]);
    return root[u];
}
bool mergeSet(int u, int v ) {
    u = findRoot(u), v = findRoot(v);
    if (u == v) return false;

    if  (level[u] == level[v])
        level[u]++;
    if (level[u] > level[v])
        root[u] = v; else root[v] = u

    return true;
}


signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    makeSet();
    int u, v, c;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> c;
        edge.push_back({c,{u, v}});
    }
    sort(edge.begin(), edge.end());
    ll res = 0;
    for (auto e : edge) {
        if (mergeSet(e.second.first, e.second.second))
            res += e.first;
    }
    cout << res;
}
