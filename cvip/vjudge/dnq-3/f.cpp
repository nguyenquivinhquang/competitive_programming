#include <bits/stdc++.h>
#define ll long long
#define maxn 30
using namespace std;
int n, m, half;
ll k;
ll a[maxn][maxn];
map<ll, ll> trace[maxn][maxn];
ll res = 0;
void compute1(int x, int y, int step, ll cur)
{
    cur ^= a[x][y];
    if (step == half)
    {
        trace[x][y][cur]++;
        return;
    }
    if (x + 1 <= n)
        compute1(x + 1, y, step + 1, cur);
    if (y + 1 <= m)
        compute1(x, y + 1, step + 1, cur);
}
void compute2(int x, int y, int step, ll cur)
{
    if (step == n + m - 2 - half)
    {
        if (trace[x][y].count(k ^ cur))
        {
            res += trace[x][y][k ^ cur];
        }
        return;
    }
    if (x > 1)
        compute2(x - 1, y, step + 1, cur ^ a[x][y]);
    if (y > 1)
        compute2(x, y - 1, step + 1, cur ^ a[x][y]);
}

int main()
{

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    half = (n + m) / 2;
    compute1(1, 1, 0, 0);
    compute2(n, m, 0, 0);
    if (n == 1 && m == 1&&a[n][m]==k)
        res = 1;
    cout << res;
}

/*
5
12 353 33 87 99
*/