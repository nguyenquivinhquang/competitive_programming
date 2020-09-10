#include <bits/stdc++.h>
#define N 1005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(a, val) memset(a, val, sizeof(a));
#define modulo int(1e9 + 7)
#define endl '\n'
#define inf 1e9
using namespace std;
ll x, n, m, t, cost[N], timet[N], d[N][N];
vector<pair<pair<int, int>, int>> vertice[N][N];
void dijkstra()
{
    for (int i = 1; i < N; i++)
        for (int j = 0; j < N; j++)
            d[i][j] = inf;
    set<pair<int, pp>> q;
    d[1][timet[1]] = 0;
    q.insert({0, {1, timet[1]}});
    while (q.size() != 0)
    {
        pp temp = q.begin()->second;
        q.erase(q.begin());
        int u, v;
        for (auto edge : vertice[temp.first][temp.second])
        {
            //pp to = edge.first;
            int len = edge.second;
            tie(u, v) = edge.first;
            if (d[temp.first][temp.second] + len < d[u][v])
            {
                q.erase({d[u][v], edge.first});
                d[u][v] = d[temp.first][temp.second] + len;
                q.insert({d[u][v], edge.first});
            }
        }
    }
    if (d[1][x] == inf)
        cout << "It is a trap.";
    else
        cout << d[1][x] + cost[1];
    
}
int main()
{
    int u, v;
    cin >> x;
    cin >> n >> m >> t;

    vector<pair<int, int>> edges;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        edges.emplace_back(u, v);
    }
    for (int i = 1; i <= n; i++)
        cin >> timet[i] >> cost[i];

    for (auto e : edges)
    {
        tie(u, v) = e;

        for (int t1 = 0, t2 = timet[v] + t; t2 <= x; t1++, t2++)
        {
            vertice[u][t1].push_back({make_pair(v, t2), cost[v]});
        }
        for (int t1 = 0, t2 = timet[u] + t; t2 <= x; t1++, t2++)
        {
            vertice[v][t1].push_back({make_pair(u, t2), cost[u]});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int t1 = 0, t2 = timet[i]; t2 <= x; t1++, t2++)
        {
            vertice[i][t1].push_back({make_pair(i, t2), cost[i]});
        }
    }

    // answer = cost[1] + dijkstra from (1, timet[t1]) to (1, x)
    dijkstra();
}
