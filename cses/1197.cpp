#include <bits/stdc++.h>
#define N 100
#define ll long long int
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(a, val) memset(a, val, sizeof(a));
#define modulo int(1e9 + 7)
#define endl '\n'
const ll INF = 1000000000;
using namespace std;
struct Edge
{
    ll a, b, cost;
};

int n, m;
vector<Edge> edges;

void solve()
{
    vector<ll> d(n + 10);
    vector<ll> p(n + 10, -1);
    ll x;
    for (int i = 0; i < n; ++i)
    {
        x = -1;
        for (Edge e : edges)
        {
            if (d[e.a] + e.cost < d[e.b])
            {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1)
    {
        cout << "NO";
    }
    else
    {
        for (int i = 0; i < n; ++i)
            x = p[x];

        vector<ll> cycle;
        for (int v = x;; v = p[v])
        {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES \n";
        for (auto v : cycle)
            cout << v << ' ';
        cout << endl;
    }
}

int main()
{
    Edge temp;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> temp.a >> temp.b >> temp.cost;
        edges.push_back(temp);
    }
    solve();
}