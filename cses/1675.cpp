#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 200009;

using namespace std;
int n, m;
struct Edge {
    int u, v, w;
};
bool cmp(Edge &x, Edge &y) {
    return x.w < y.w;
}
vector<Edge> edge;
int level[N], parent[N];
void makeSet() {
    for (int i = 0; i < n; i++)
        parent[i] = i, level[i] = 0;
}
int find_set(int u) {
    if (u == parent[u])
        return u;
    return parent[u] = find_set(parent[u]);
    //return parent[u];
}
void union_set(int a, int b) {
    a = find_set(a), b = find_set(b);
    if (a == b) return;
    if (level[a] < level[b]) swap(a, b);
    parent[b] = a;
    if (level[a] == level[b]) level[a]++;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int x, y, w, res = 0;
    ll cost = 0;

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> w;
        edge.push_back({x - 1, y - 1, w});
    }
    makeSet();
    sort(edge.begin(), edge.end(), cmp);
    for (auto e : edge) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.w;
            union_set(e.u, e.v);
            res++;
        }
    }
    if (res == n - 1)
        cout << cost;
    else cout << "IMPOSSIBLE";
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/