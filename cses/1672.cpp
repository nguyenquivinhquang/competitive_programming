#include <bits/stdc++.h>
#define N 505
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
#define reset(a,val) memset(a,val,sizeof(a));
#define modulo int(1e9+7)
#define endl '\n'
#define inf 1e18
using namespace std;
ll d[N][N], n, m;
int main()
{
    fastio;
    for (int i = 1; i <= 501; i++)
        for (int j = 1; j <= 501; j++)
            d[i][j] = inf;
    ll x, y, q, w;
    cin >> n >> m >> q;

    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> w;
        d[x][y] = d[y][x] = min(w, d[x][y]);
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (d[i][k] < inf && d[k][j] < inf)
                {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }


    while (q--)
    {
        cin >> x >> y;
        if (x == y) d[x][y] = 0;
        if (d[x][y] == inf)
            d[x][y] = -1;
        cout << d[x][y] << endl;
    }
}