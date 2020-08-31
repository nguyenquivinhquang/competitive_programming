//https://www.spoj.com/problems/QTREE2/
#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include <map>
#define N 10005
#define ll long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))

using namespace std;
ll n, level[N + 7], dp[N + 7][21], lgn, dist[N + 7];
map<int, int> len[N + 7];
vector<int> vertice[N + 7];
void dfs(int u, int preu)
{
    level[u] = level[preu] + 1;
    dp[u][0] = preu;
    dist[u] = dist[preu] + len[u][preu];
    for (int i = 1; i <= lgn; i++)
        dp[u][i] = dp[dp[u][i - 1]][i - 1];
    for (auto v : vertice[u])
    {
        if (v == preu)
            continue;
        dfs(v, u);
    }
}
ll lca(ll u, ll v)
{
    if (level[u] < level[v])
        swap(u, v);
    unsigned int diff = level[u] - level[v];
    for (int i = lgn; i >= 0; i--)
    {
        if (1 << i & diff)
            u = dp[u][i];
    }
    if (u == v)
        return u;
    for (int i = lgn; i >= 0; i--)
        if (dp[u][i] != dp[v][i] && dp[u][i] != -1)
        {
            u = dp[u][i];
            v = dp[v][i];
        }
    return dp[u][0];
}
void solve()
{
    string query;
    ll x, y, k, root;
    cin >> n;
    dist[0] = 0, level[0] = 0, len[1][0] = 0;
    reset(dp, -1);
    lgn = ceil(log2(n));
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y >> k;
        vertice[x].push_back(y);
        vertice[y].push_back(x);
        len[x][y] = len[y][x] = k;
    }
    dfs(1, 1);
    while (cin >> query)
    {
        if (query == "DONE")
            break;
        if (query == "DIST")
        {
            cin >> x >> y;
            root = lca(x, y);
            cout << dist[x] - dist[root] + dist[y] - dist[root] << endl;
        }
        else
        {
            cin >> x >> y >> k;
            root = lca(x, y);
            if (level[x] - level[root] < k)
            {
                k = (level[y] - level[root] + 1) - (k - level[x] + level[root]);
                for (int i = lgn; i >= 0; i--)
                {
                    if (1 << i & k)
                        y = dp[y][i];
                }
                cout << y << endl;
            }
            else
            {
                k--;
                for (int i = lgn; i >= 0; i--)
                {
                    if (1 << i & k)
                        x = dp[x][i];
                }
                cout << x << endl;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        vertice[i].clear();
}
int main()
{
    fastio;
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
        cout << endl;
    }
}