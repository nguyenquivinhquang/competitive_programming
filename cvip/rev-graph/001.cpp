#include <bits/stdc++.h>
#define N 200005
#define ll long long
#define pp pair<ll, ll>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(a, val) memset(a, val, sizeof(a));
#define modulo int(1e9 + 7)
#define endl '\n'
using namespace std;
struct infor
{
    ll val, number;
};
struct query_type
{
    ll u, v, c;
};
int n, m;
vector<pp> edge[N], edge2[N];
vector<query_type> query;
infor d[N], s[N];
set<int> pre[N];
set<pair<pair<int, int>, ll>> path;

bool fee[N];
bool cmp(query_type a, query_type b)
{
}
void dijsktra()
{
    set<pp> q;

    for (int i = 1; i <= n; i++)
        s[i].val = d[i].val = 1e18, s[i].number = d[i].number = 1;
    s[2].val = d[1].val = 0, d[2].number = d[1].number = 1;
    q.insert({0, 1});
    while (q.size() != 0)
    {
        ll u = q.begin()->second;
        q.erase(q.begin());
        for (auto e : edge[u])
        {
            ll to = e.first, len = e.second;
            if (d[u].val + len <= d[to].val)
            {
                q.erase({d[to].val, to});
                if (d[u].val + len == d[to].val)
                {
                    d[to].number += d[u].number;
                    d[to].number %= modulo;
                    pre[to].insert(u);
                }
                else
                {
                    d[to] = d[u];
                    d[to].val += len;
                    pre[to].clear();
                    pre[to].insert(u);
                }
                q.insert({d[to].val, to});
            }
        }
    }
    //reset(s, -1);
    q.clear();
    q.insert({0, 2});
    while (q.size() != 0)
    {
        ll u = q.begin()->second;
        q.erase(q.begin());
        for (auto e : edge2[u])
        {
            ll to = e.first, len = e.second;
            if (s[u].val + len <= s[to].val)
            {
                q.erase({s[to].val, to});
                if (s[u].val + len == s[to].val)
                {
                    s[to].number += s[u].number;
                    s[to].number %= modulo;
                }
                else
                {
                    s[to] = s[u];
                    s[to].val += len;
                }
                q.insert({s[to].val, to});
            }
        }
    }
}
void trace(int u)
{
    for (auto v : pre[u])
    {
        path.insert({{v, u}, d[u].val - d[v].val});
        if (fee[v] == true)
        {
            fee[v] = false;
            trace(v);
        }
    }
}
void solve()
{
    int u, v, c;
    for (auto x : query)
    {
        u = x.u, v = x.v, c = x.c;

        if (path.find({{u, v}, c}) != path.end())
        {
            if (d[u].number * s[v].number == d[2].number)
                cout << "SAD";
            else
                cout << "SOSO";
        }
        else
        {
            if (d[v].val + s[u].val + c < d[2].val)
                cout << "HAPPY ";
            else
                cout << "SOSO";
        }
        cout << endl;
    }
}
int main()
{

    fastio;
    int x, y, c;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> c;
        edge[x].push_back({y, c});
        edge2[y].push_back({x, c});
        query.push_back({x, y, c});
    }
    dijsktra();
    reset(fee, true);
    trace(2);
    solve();
}
