#include <bits/stdc++.h>
#define maxn 501
using namespace std;
int n, m, dp[maxn][maxn], x, y;
void debug()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (i == j) dp[i][j] = 1;
            else
            {
                x = min(i, j);
                y = min(i, j);
                if (j - y == x || i - x == y) dp[i][j] = 1;
                else if (x - i == 0) dp[i][j] = (dp[x][j - y] + 1);
                else if (y - j == 0)	dp[i][j] = dp[i-x][y] + 1;
            }
    debug();
    //cout << dp[n][m];
}