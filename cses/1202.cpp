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
    ll min_val, number, min_flight, max_flight;
};
int n, m;
vector<pp> edge[N];
void dijsktra()
{
    set<pp> q;
    infor d[N];
    for (int i = 1; i <= n; i++)
        d[i].min_val = 1e18, d[i].number = 1, d[i].min_flight = 0, d[i].max_flight = 0;
    d[1].min_val = 0, d[1].number = 1;
    q.insert({0, 1});
    while (q.size() != 0)
    {
        ll u = q.begin()->second;
        q.erase(q.begin());
        for (auto e : edge[u])
        {
            ll to = e.first, len = e.second;
            if (d[u].min_val + len <= d[to].min_val)
            {
                q.erase({d[to].min_val, to});
                if (d[u].min_val + len == d[to].min_val)
                {
                    d[to].number += d[u].number;
                    d[to].number %= modulo;
                    d[to].min_flight = min(d[to].min_flight, d[u].min_flight + 1);
                    d[to].max_flight = max(d[to].max_flight, d[u].max_flight + 1);
                }
                else
                {
                    d[to] = d[u];
                    d[to].min_val += len;
                    d[to].min_flight++, d[to].max_flight++;
                }

                q.insert({d[to].min_val, to});
            }
        }
    }
    cout << d[n].min_val << " " << d[n].number << " " << d[n].min_flight << " " << d[n].max_flight;
    // for (int i = 1; i <= n; i++)
    //     cout << d[i].number << " ";
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
    }
    dijsktra();
}