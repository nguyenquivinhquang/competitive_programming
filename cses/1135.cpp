#include <bits/stdc++.h>
#define N 200005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
int n, level[N], lgn, dp[N][20];
vector<int> vertices[N];

void dfs(int u, int preu)
{
    level[u] = level[preu] + 1;
    dp[u][0] = preu;
    if (u == 1)
        dp[u][0] = -1;
    for (int i = 1; i < lgn; i++)
        dp[u][i] = dp[dp[u][i - 1]][i - 1];
    for (int v : vertices[u])
    {
        if (preu == v)
            continue;
        dfs(v, u);
    }
}
int lca(int u, int v)
{
    int res = 0;
    if (level[u] < level[v])
        swap(u, v);
    unsigned int diff = level[u] - level[v];
    for (int i = lgn; i >= 0; i--)
    {
        if (1 << i & diff)
        {
            u = dp[u][i];
            res += pow(2, i);
        }
    }
    if (u == v)
        return res;
    for (int i = lgn; i >= 0; i--)
        if (dp[u][i] != dp[v][i])
        {
            u = dp[u][i];
            v = dp[v][i];
            res += pow(2, i) * 2;
        }
    return res + 2;
}

int main()
{
    int q, x, y;
    reset(level, 0), reset(dp, -1);
    cin >> n >> q;
    lgn = ceil(log2(n));
    for (int i = 2; i <= n; i++)
    {
        cin >> x >> y;
        vertices[x].push_back(y), vertices[y].push_back(x);
    }
    dfs(1, 1);
    while (q--)
    {
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }
}