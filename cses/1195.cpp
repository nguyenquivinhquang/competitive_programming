#include <bits/stdc++.h>
#define N 200006
#define ll long long
#define pp pair<ll,ll>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
#define reset(a,val) memset(a,val,sizeof(a));
#define modulo int(1e9+7)
#define endl '\n'
const ll inf = 2556648384776000;
using namespace std;
ll n, m, d1[N], d2[N];
vector <pp> edge[N], edge2[N];

void dijkstra1()
{
    for (int i = 1; i <= n; i++)
        d1[i] = d2[i] = inf;
    set<pp>q;
    d1[1] = 0;
    q.insert({0, 1});
    while (q.size() != 0)
    {
        int u = q.begin()->second;
        q.erase(q.begin());
        for (auto v : edge[u])
        {
            int to = v.first, len = v.second;
            if (d1[u] + len < d1[to])
            {
                q.erase({d1[to], to});
                d1[to] = d1[u] + len;
                q.insert({d1[to], to});
            }
        }
    }
    d2[n] = 0;
    q.clear();
    q.insert({0, n});
    while (q.size() != 0)
    {
        int u = q.begin()->second;
        q.erase(q.begin());
        for (auto v : edge2[u])
        {
            int to = v.first, len = v.second;
            if (d2[u] + len < d2[to])
            {
                q.erase({d2[to], to});
                d2[to] = d2[u] + len;
                q.insert({d2[to], to});
            }
        }
    }
    ll res = inf;
    for (int u = 1; u <= n; u++)
    {
        for (auto v : edge[u] )
        {
            if (v.first != u)
                res = min(res, d1[u] + d2[v.first] + v.second / 2);
        }
    }
    cout << res;
}
int main()
{
    int x, y, c;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> c;
        edge[x].push_back({y, c});
        edge2[y].push_back({x, c});
    }
    dijkstra1();
}