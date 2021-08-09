#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 100009;

using namespace std;
pair<int, pp> a[N];
int n, root[N], level[N];
ll res = 0;
vector<pair<int, pp>> vertice;
bool cmpY(pair<int, pp> &u, pair<int, pp> &v) {
    return u.second.second < v.second.second;
}
bool cmpX(pair<int, pp> &u, pair<int, pp> &v) {
    return u.second.first < v.second.first;
}
void buildGraph() {
    sort(a + 1, a + 1 + n, cmpX);
    for (int i = 1; i < n; i++) {
        int u = a[i].first, v = a[i + 1].first;
        int len = a[i + 1].second.first - a[i].second.first;
        vertice.push_back({len, {u, v}});
    }
    sort(a + 1, a + 1 + n, cmpY);
    for (int i = 1; i < n; i++) {
        int u = a[i].first, v = a[i + 1].first;
        int len = a[i + 1].second.second - a[i].second.second;
        vertice.push_back({len, {u, v}});
    }
}
void makeSet() {
    for (int i = 1; i <= n; i++)
        root[i] = i, level[i] = 0;
}
int findRoot(int u) {
    if (u == root[u]) return u;
    root[u] = findRoot(root[u]);
    return root[u];
}
void join(int u, int v, int c) {
    u = findRoot(u);
    v = findRoot(v);
    if (u == v) return;
    if (level[u] == level[v]) level[u]++;
    if (level[u] > level[v]) swap(u, v);
    root[u] = v;
    res += c;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    int id, x, y;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        a[i] = {i, {x, y}};
    }
    buildGraph();
    makeSet();
    sort(vertice.begin(), vertice.end());
    for (auto v : vertice) {
        join(v.second.first, v.second.second, v.first);
        // cout <<v.second.second << " " << v.second.first << " " << v.first << endl;
    }
    cout << res;
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/