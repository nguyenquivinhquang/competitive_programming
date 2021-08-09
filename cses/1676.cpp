#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 100009;

using namespace std;
int root[N], level[N], comp[N], n, m;
multiset<int, greater<>> compSize;
void makeSet() {
    for (int i = 1; i <= n; i++) {
        level[i] = 0;
        root[i] = i;
        compSize.insert(1);
        comp[i] = 1;
    }
}
int find_parent(int u) {
    if (u == root[u]) return u;
    return root[u] = find_parent(root[u]);
}
void unionSet(int u, int v) {
    u = find_parent(u), v = find_parent(v);
    if (u == v) return;
    if (level[u] < level[v]) swap(u, v);
    root[v] = u;
    compSize.erase(compSize.lower_bound(comp[u]));
    compSize.erase(compSize.lower_bound(comp[v]));
    comp[u] += comp[v];
    compSize.insert(comp[u]);
    if (level[v] == level[u]) level[u]++;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int x, y;
    cin >> n >> m;
    makeSet();
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        unionSet(x, y);
        cout << compSize.size() << " " << *compSize.begin() << "\n";
    }
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/