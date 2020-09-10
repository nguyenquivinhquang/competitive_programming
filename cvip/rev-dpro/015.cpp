#include <bits/stdc++.h>
#define N 1005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(a, val) memset(a, val, sizeof(a));
#define modulo int(1e9 + 7)
#define endl '\n'
using namespace std;
int n, k, color[N], c = 0, group[N], pre[N], chill[N], d = 0, bag[N], err[N];
int dp[N];
vector<int> vertice[N];
void create_new(int u, int v)
{
    c++;
    group[u] = group[v] = c;
    while (u != v)
    {
        v = pre[v];
        group[v] = c;
    }
}
void dfs(int u)
{
    color[u] = d;
    for (auto v : vertice[u])
    {
        if (group[v] == 0 && color[v] == color[u])
        {

            create_new(v, u);
            return;
        }
        if (group[v] == 0)
        {
            pre[v] = u;
            dfs(v);
        }
    }
}
void dfs2(int u)
{
    color[u] = 1;
    for (auto v : vertice[u])
    {
        if (group[v])
        {
            chill[u] = group[v];
            return;
        }
        if (color[v] == 0)
            dfs2(v);
        chill[u] = chill[v];
    }
}
int main()
{
    fastio;
    reset(color, 0) reset(group, 0) reset(pre, -1) reset(bag, 0) reset(err, 0);
    int temp;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        vertice[i].push_back(temp);
    }

    for (int i = 1; i <= n; i++)
        if (color[i] == 0)
        {
            d++;
            dfs(i);
        }
    for (int i = 1; i <= n; i++)
    {
        bag[group[i]]++;
        err[group[i]]--;
    }
    reset(color, 0);
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
            dfs2(i);
    }
    for (int i = 1; i <= n; i++)
        err[chill[i]]++;
    // for (int i = 1; i <= n; i++)
    //     cout << err[i];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        if (bag[i])
            for (int j = k; j >= 1; j--)
            {
                for (int t = 0; t <= err[i]; t++)
                    if (j - bag[i] - t >= 0 && dp[j - bag[i] - t] == 1)
                        dp[j] = 1;
            }
    for (int i = k; i >= 1; i--)
        if (dp[i] == 1)
        {
            cout << i;
            return 0;
        }
    cout << 0;
}