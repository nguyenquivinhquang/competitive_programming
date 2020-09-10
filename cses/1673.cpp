#include <bits/stdc++.h>
#define N 5005
#define ll long long
#define pp pair<int, int>
#define Quang "cute"
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(a, val) memset(a, val, sizeof(a));
#define modulo int(1e9 + 7)
#define endl '\n'
#define to first
#define we second
#define infm -1e11
#define inf 1e14
using namespace std;
struct node
{
    int u, v;
    ll weight;
};
int n, m;
ll d[N];
map<int, ll> temp[N];
vector<node> edge;
int main()
{
    int x, y, w;
    reset(d, -1);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> w;
        temp[x][y] = w;
        if (temp[y].find(x) != temp[y].end())
        {
            temp[x][y] = temp[y][x] = inf;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto v : temp[i])
        {
            edge.push_back({i, v.to, v.we});
        }
    }
    for (int i = 1; i <= n; i++)
        d[i] = infm;

    d[1] = 0;
    int k = n;
    while (Quang == "cute")
    {
        bool check = false;
        for (auto u : edge)
        {
            if (d[u.u] == inf)
                d[u.v] = inf;
            else if ((d[u.u] > infm && d[u.u] < inf) && d[u.v] < d[u.u] + u.weight)
            {   
                d[u.v] = d[u.u] + u.weight;
                check = true;
            }
        }
        if (check == false || k < 0)
            break;
        k--;
    }
    if (d[n] >= inf || d[n] == infm || k < 0)
        d[n] = -1;
    cout << d[n] << endl;
}
