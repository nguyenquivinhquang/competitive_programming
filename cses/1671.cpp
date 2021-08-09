#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define pp pair<ll,ll>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
#define reset(a,val) memset(a,val,sizeof(a));
#define modulo int(1e9+7)
#define endl '\n'
#define to v.first
#define len v.second
using namespace std;
ll n, m, d[N];
vector<pp> vertice[N];
 
void dijkstra()
{
    set<pp> q;
    d[1] = 0;
    q.insert({0, 1});
    while (q.size())
    {
        int u = q.begin()->second;
        q.erase(q.begin());
        for (auto v : vertice[u])
        {
            if (d[u] + len < d[to])
            {
                q.erase({d[to], to});
                d[to] = d[u] + len;
                q.insert({d[to], to});
            }
        }
    }
}
int main()
{
 
    ll x, y, w;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> w;
        vertice[x].push_back({y, w});
    }
 
    for (int i = 1; i <= n; i++)
    {
        d[i] = 1e17;
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
}