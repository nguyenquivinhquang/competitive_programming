#include <bits/stdc++.h>
#define reset for (int i=1; i<=n; i++) dp[i][0]=0, dp[0][i]=0, dp[i][n+1]=0, dp[n+1][i]=0
using namespace std;
 
int main()
{
    int n;
    char temp;
    cin >> n;
    bool a[n + 1][n + 1];
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    reset;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> temp;
            if (temp == '.') a[i][j] = 1;
            else a[i][j] = 0;
 
 
        }
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if ( a[i - 1][j] == 1) dp[i][j] += dp[i - 1][j];
            if ( a[i][j - 1] == 1) dp[i][j] += dp[i][j - 1];
            dp[i][j] %= 1000000007;
            //cout << dp[i][j];
        }
    if ( a[n][n] == 0) dp[n][n] = 0;
    cout << dp[n][n];
}