#include <bits/stdc++.h>
#define N 10005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;
vector<int> vertice[N];
pp tt[N]; // first: remaining marbles, second: childrens dont have marbles
int n, marble[N];
ll res;
void dfs(int u, int preU)
{
    tt[u].first = marble[u];
    tt[u].second = 1;
    for (auto v : vertice[u])
    {
        if (v == preU)
            continue;
        dfs(v, u);
        tt[u].first += tt[v].first;
        tt[u].second += tt[v].second;
    }
    if (tt[u].first - tt[u].second >= 0)
    {
        tt[u].first -= tt[u].second;
        tt[u].second = 0;
    }
    else
    {
        tt[u].second -= tt[u].first;
        tt[u].first = 0;
    }
    res += max(tt[u].second, tt[u].first);
}
int main()
{
    // input_file;
    // output_file;
    fastio;
    int testcase;
    while (cin >> n)
    {
        if (n == 0)
            break;
        res = 0;
        for (int i = 1; i <= n; i++)
        {
            int u, m, temp;
            cin >> u >> marble[u] >> m;
            for (int i = 1; i <= m; i++)
            {
                cin >> temp;
                vertice[temp].push_back(u);
                vertice[u].push_back(temp);
            }
        }
        dfs(1, -1);
        cout << res << endl;
        // clear ver
        for (int i = 1; i <= n; i++)
            vertice[i].clear();
    }
}