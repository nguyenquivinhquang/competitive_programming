#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define modulo int(1e9 + 7)
using namespace std;
ll n, m, node[N], sum[N], val[N];
vector<int> vertice[N];
void dfs1(int u, int preU)
{
    node[u] = 1, sum[u] = val[u];
    for (int v : vertice[u])
    {
        if (v == preU)
            continue;
        dfs1(v, u);
        node[u] += node[v];
        sum[u] += node[v] * val[u] + sum[v];
    }
}
void dfs2(int u, int preU)
{
    if (u != 1)
    {
        ll t = sum[preU] - sum[u] - node[u] * val[preU];
        sum[u] += t + (node[preU] - node[u]) * val[u];
        node[u] = n;
    }
    for (auto v : vertice[u])
    {
        if (v == preU)
            continue;
        dfs2(v, u);
    }
}
void solve()
{
    int x, y;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        vertice[x].push_back(y);
        vertice[y].push_back(x);
        val[i] = 1;
    }
    val[n] = 0;
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> val[i];
    dfs1(1, 0);
    for (int i = 1; i <= n; i++)
        cout << sum[i] << " ";
    cout << endl;
    dfs2(1, 0);
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = (res + sum[i]) % modulo;
        vertice[i].clear();
    }
    cout << res << endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}