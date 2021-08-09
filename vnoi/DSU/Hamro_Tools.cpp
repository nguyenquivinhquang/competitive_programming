//https://codeforces.com/group/L1Sf9F4uBt/contest/200499/problem/E

#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
int parent[N + 3], DSU_rank[N + 3], box[N], tool[N];
void makeSet(int x)
{
    reset(DSU_rank);

    for (int i = 1; i <= x; i++)
        parent[i] = box[i] = tool[i] = i;
}
int findParent(int x)
{
    if (x != parent[x])
        parent[x] = findParent(parent[x]);
    return parent[x];
}
int join(int u, int v)
{
    u = findParent(u), v = findParent(v);
    if (u == v)
        return u;
    if (DSU_rank[u] == DSU_rank[v])
        DSU_rank[u]++;
    if (DSU_rank[u] > DSU_rank[v])
    {
        parent[v] = u;
        return u;
    }
    parent[u] = v;
    return v;
}
void solve()
{
    int n, q, x, y;
    cin >> n >> q;
    makeSet(n);
    while (q--)
    {
        cin >> x >> y;
        if (box[x] + box[y] == 0 || box[x] == 0)
            continue;
        if (box[y] == 0)
        {
            box[y] = box[x], box[x] = 0;
            tool[box[y]] = y;
            continue;
        }
        box[y] = join(box[x], box[y]), box[x] = 0;
        tool[box[y]] = y;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << tool[findParent(i)] << " ";
    }
}
int main()
{
    solve();
}
