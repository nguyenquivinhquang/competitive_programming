#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
int dp[N][N];
char a[N][N], res[N][N];
int main()
{
    reset(dp, -1);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            res[i][j] = '.';
        }

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '.')
            {
                if (dp[i + 1][j] != -1)
                    dp[i][j] = dp[i + 1][j];
                else
                    dp[i][j] = i;
            }
            else if (a[i][j] == '#')
            {
                dp[i][j] = -1;
                res[i][j] = a[i][j];
            }
            else
            {
                if (dp[i + 1][j] != -1)
                {
                    res[dp[i + 1][j]][j] = 'o';
                    dp[i][j] = dp[i + 1][j] - 1;
                }
                else
                {
                    res[i][j] = 'o';
                    dp[i][j] = -1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << res[i][j];
        cout << endl;
    }
}