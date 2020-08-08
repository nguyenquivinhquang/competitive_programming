#include <bits/stdc++.h>
#define maxn 1001

using namespace std;
int n, m, a[maxn][maxn], trace[maxn][maxn], road[maxn * maxn], x_s, y_s, x_e, y_e;
void dfs(int u, int v, int step)
{
    if (trace[u][v] == false || a[u][v] == 1)
        return;
    trace[u][v] = false;
    dfs(u + 1, v, step + 1);
    dfs(u, v + 1, step + 1);
    dfs(u - 1, v, step + 1);
    dfs(u, v - 1, step + 1);
}
int main()
{
    cin >> n >> m;

    char temp;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> temp;
            if (temp == '#')
                a[i][j] = 1;
            else
                a[i][j] = 0;
            trace[i][j] = true;
        }
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (trace[i][j] == true && a[i][j] == 0)
            {
                res++;
                //trace[i][j] = false;
                dfs(i, j);
            }
    cout << res;
}