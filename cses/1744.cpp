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
            if (i == j) dp[i][j] = 0;
            else
            {
                dp[i][j] = i * j;
                for (int x = 1; x <= i / 2; x++)
                {

                    dp[i][j] = min(dp[x][j] + dp[i - x][j] + 1, dp[i][j]);
                }
                for (int y = 1; y <= j / 2; y++)
                {

                    dp[i][j] = min(dp[i][y] + dp[i][j - y] + 1, dp[i][j]);
                }

            }
    //debug();
    cout << dp[n][m];
}