#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
#define modulo int(1e9+7)
#define output freopen("output.txt","w",stdout)
using namespace std;
int n, edge[N], sum[N];
vector<ll> vertice[N];
map<ll, ll> weigth[N];
void dfs1(int u, int preU)
{
    for (auto v : vertice[u])
    {
        if (v == preU)
            continue;
        dfs1(v, u);
        edge[u] += edge[v] + 1;
        sum[u] += (weigth[u][v] * (edge[v] + 1) + sum[v]) % modulo;
    }
}   
void dfs2(int u, int preU)
{

}
void solve()
{
    int x, y, k;
    ll res = 0;
    memset(sum, sizeof(sum), 0);
    memset(edge, sizeof(edge), 0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y >> k;
        vertice[x].push_back(y);
        vertice[y].push_back(x);
        weigth[x][y] = weigth[y][x] = k;
    }
    dfs1(1, 0);
    for (int i = 1; i <= n; i++)
    {
        //res = (sum[i] + (sum[i] * (vertice[i].size() - 1)) % modulo) % modulo;
        //res %= modulo;
    	cout << sum[i] <<" ";
    }
    cout << res << endl;
}
int main()
{
    //output;
    int testcase;
    cin >> testcase;
    for (int i = 1; i <= testcase; i++)
    {
        solve();
    }
}