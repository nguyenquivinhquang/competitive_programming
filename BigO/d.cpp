#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
set<int> diff[N];
int root[N], Rank[N], vertice[N];
unordered_map<int,int> total;
void makeSet() {
    for (int i = 1; i < N; i++) {
        root[i] = i;
        diff[i].insert(vertice[i]);
    }
}
int find(int x) {
    if (x != root[x])
        root[x] = find(root[x]);
    return root[x];
}
void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
        return; 
    if (Rank[u] == Rank[v])
        Rank[u]++;
    if (Rank[u] > Rank[v])
        swap(u, v);
    root[v] = u;
    if (diff[u].size() < diff[v].size())
        swap(diff[u], diff[v]);
    for (auto t : diff[v]) {
        if (diff[u].find(t) != diff[u].end()) 
            total[t]--;
        else diff[u].insert(t);
    }
    diff[v].clear();
}
void solve() {
    reset(root);
    reset(Rank);

    int n, x, y, q, t;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> vertice[i];
        total[vertice[i]]++;
    }
    makeSet();
    for (int i = 1; i <= q; i++) {
        cin >> t;
        if (t == 1) {
            cin >> x >> y;
            join(x, y);
        }
        else {
            cin >> x;
            cout << total[x] << "\n";
        }

    }
}
int main() {
    int testcase;
    solve();
}