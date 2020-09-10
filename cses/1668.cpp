#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
#define reset(a,val) memset(a,val,sizeof(a));
#define modulo int(1e9+7)
#define endl '\n'
using namespace std;
int n, m, bipartite[N];
vector<int> vertice[N];
bool fee[N], check = true;
void dfs(int u)
{
    int team = bipartite[u];
    for (int v : vertice[u])
    {
        if (bipartite[v] == team)
            check = false;
        if (fee[v] == false)
            continue;
        bipartite[v] = 3 - team;
        fee[v] = false;
        dfs(v);
    }

}
int main()
{
    int x, y;
    reset(bipartite, 0);
    reset(fee, true);

    cin >> n >> m;
    for (int i = 1; i <= m ; i++)
    {
        cin >> x >> y;
        vertice[x].push_back(y);
        vertice[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (fee[i] == false)
            continue;
        bipartite[i] = 1;
        dfs(i);
    }
    if (check)
    {
        for (int i = 1; i <= n; i++)
            cout << bipartite[i] << " ";
    }
    else cout << "IMPOSSIBLE";
}