#include <bits/stdc++.h>
#define maxn 500
#define pp pair<int, int>
using namespace std;
vector<int> edge[maxn];
int n, m;
bool fee[maxn][maxn];
int bfs()
{
    queue<pp> q;
    bool visit[maxn];
    memset(visit, 0, sizeof(visit));
    pp temp;
    temp = {1, 0};
    q.push(temp);
    while (!q.empty())
    {
        temp = q.front();
        int u = temp.first;
        visit[u] = 1;
        for (auto v : edge[u])
            if (u != v && visit[v] == 0)
            {
                if (v == n)
                    return temp.second + 1;
                visit[v] = 1;
                q.push({v, temp.second + 1});
            }
        q.pop();
    }
    return -1;
}
int main()
{
    int u, v, res1, res2;
    memset(fee, 0, sizeof(fee));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        fee[u][v] = 1, fee[v][u] = 1;
    }
    res1 = bfs();
    for (int i = 1; i <= n; i++)
        edge[i].clear();

    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            if (fee[u][v] == 0 && u != v)
            {
                edge[u].push_back(v);
                edge[v].push_back(u);
            }
    res2 = bfs();
    if (res1 == -1 || res2 == -1)
        cout << -1;
    else
    {
        cout << max(res1, res2);
    }
}