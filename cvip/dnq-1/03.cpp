#include <bits/stdc++.h>
#define maxn 105
#define ll long long
#define mod %
#define el '\n'
#define fileinp "D:\\c++\\cvip\\dnq-1\\3.inp"
using namespace std;

int a[maxn][maxn], n;
bool trace[maxn][maxn];
int res = 1000000000;

//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa//
bool dfs(int x, int y, int h_max, int h_min)
{
    //if (h_max < h_min)
    //    swap(h_max, h_min);
    if (a[x][y] > h_max || a[x][y] < h_min)
        return false;

    bool check = false;
    if (x > n || x < 1 || y > n || y < 1)
        return false;

    trace[x][y] = false;
    if (x == n && y == n)
        return true;
    if (x + 1 <= n && trace[x + 1][y] == true && a[x + 1][y] <= h_max && a[x + 1][y] >= h_min)
        check = check | (dfs(x + 1, y, h_max, h_min));

    if (x - 1 > 0 && trace[x - 1][y] == true && a[x - 1][y] <= h_max && a[x - 1][y] >= h_min)
        check = check | (dfs(x - 1, y, h_max, h_min));

    if (y + 1 <= n && trace[x][y + 1] == true && a[x][y + 1] <= h_max && a[x][y + 1] >= h_min)
        check = check | (dfs(x, y + 1, h_max, h_min));

    if (y - 1 >= 1 && trace[x][y - 1] == true && a[x][y - 1] <= h_max && a[x][y - 1] >= h_min)
        check = check | (dfs(x, y - 1, h_max, h_min));

    return check;
}
int main()
{
    //freopen(fileinp, "r", stdin);
    //freopen("4.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(trace, true, sizeof trace);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 0; i <= 110; i++)
        for (int j = i; j <= 110; j++)
        {
            memset(trace, true, sizeof trace);
            //cout << i << " " << j << endl;
            if (abs(i - j) <= res)
            {
                if (dfs(1, 1, j, i) == true)
                    res = abs(i - j);
            }
        }
    cout << res;
}