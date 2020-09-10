#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
#define reset(a,val) memset(a,val,sizeof(a));
#define modulo int(1e9+7)
#define endl '\n'
using namespace std;
int n, m, pre[N], color[N], cycle_start, cycle_end;
vector<int> vertice[N], res;

bool dfs(int u, int preu)
{
    color[u] = 1;
    for (int v : vertice[u])
    {
        if (v == preu) continue;
        if (color[v] == 0)
        {
            pre[v] = u;
            if (dfs(v, u))
                return true;
        }
        else if (color[v] == 1)
        {
            cycle_start = v;
            cycle_end = u;
            return true;
        }

    }
    color[u] = 2;
    return false;
}
int main()
{
    reset(pre, -1);
    reset(color, 0);
    int x, y;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        vertice[x].push_back(y);
        vertice[y].push_back(x);
    }
    cycle_end = cycle_start = -1;
    for (int i = 1; i <= n; i++)
        if (color[i] == 0 && dfs(i, 0) == true)
            break;
    if (cycle_start != -1)
    {
        res.push_back(cycle_start);
        while (cycle_end != cycle_start)
        {
            res.push_back(cycle_end);
            cycle_end = pre[cycle_end];
        }
        res.push_back(cycle_start);
        cout <<	res.size() << endl;
        for (int i : res)
            cout << i << " ";
    }
    else cout << "IMPOSSIBLE";
}