#include <bits/stdc++.h>
#define N 10005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
int root[N], Rank[N];
void makeSet() {
    for (int i = 1; i < N; i++)
        root[i] = i;
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
        root[v] = u;
    else
        root[u] = v;
}
void solve() {
    reset(root);
    reset(Rank);
    makeSet();
    int n, x, y, q;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> q;
        if (q == 1)
            join(x, y);
        else
            cout << (find(x) == find(y)) << endl;
    }
}
int main() {
    int testcase;
    solve();
}