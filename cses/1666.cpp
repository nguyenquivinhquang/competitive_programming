#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
#define reset(a,val) memset(a,val,sizeof(a));
#define modulo int(1e9+7)
#define endl '\n'
using namespace std;
vector <int> vertice[N], res;
int n, m, smlt[N], c = 0;
bool fee[N];
void dfs(int u)
{
    for (int v : vertice[u])
    {
        if (fee[v] == false)
            continue;
        fee[v] = false;
        smlt[v] = smlt[u];
        dfs(v);
    }
}
int main()
{
    int x, y;
    cin >> n >> m;
    reset(fee, true);
    reset(smlt, 0);
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        vertice[x].push_back(y);
        vertice[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (fee[i] == false )
            continue;
        fee[i] = true;
        smlt[i] = ++c;
        dfs(i);
        res.push_back(i);
    }
    cout << res.size() - 1 << endl;
    for (int i = 0; i < res.size() - 1; i++)
    {
        cout << res[i] << " " << res[i + 1] << endl;
    }
}