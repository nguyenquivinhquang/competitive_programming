//island
#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
int n, m;
char a[N][N];
bool fee[N][N];
void dfs(int u, int v)
{
    fee[u][v] = true;
    if (u == 0 || v == 0 || u > n || v > m)
        return;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
        {
            if (i * j != 0)
                continue;
            if (fee[u + i][v + j] == false && a[u + i][v + j] != 'W')
            {
                dfs(u + i, v + j);
            }
        }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    reset(fee, 0);
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (fee[i][j] == false && a[i][j] == 'L')
            {
                res++;
                dfs(i, j);
            }
    cout << res;
}