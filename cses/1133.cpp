#include <bits/stdc++.h>
#define maxn 200001
#define ll long long
using namespace std;
vector<ll> vertice[maxn];
ll n, node[maxn], sum[maxn];
void dfs(int u, int preU, int x)
{
    node[u] = 1;
    sum[u] = 0;
    for (auto v : vertice[u])
    {
        if (v == preU)
            continue;
        dfs(v, u, x + 1);
        node[u] += node[v];
        sum[u] += sum[v] + node[v];
    }
}
void dfs2(int u, int preU)
{
    if (u != 1)
    {
        ll t = sum[preU] - sum[u] - node[u];
        sum[u] += t + node[preU] - node[u];
        node[u] = n;
    }
    for (auto v : vertice[u])
    {
        if (v == preU)
            continue;
        dfs2(v, u);
    }
}
int main()
{
    int x, y;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        vertice[x].push_back(y);
        vertice[y].push_back(x);
    }

    dfs(1, 0, 0);
    sum[0] = node[1] + sum[1];
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
        cout << sum[i] << " ";
}