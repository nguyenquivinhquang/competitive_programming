#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
int root[N], Rank[N];
void makeSet(int x)
{
    root[x] = x;
    Rank[x] = 0;
}
int find(int x)
{
    if (x != root[x])
        root[x] = find(root[x]);
    return root[x];
}
void join(int u, int v)
{
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
int main()
{
    int testcase;
}