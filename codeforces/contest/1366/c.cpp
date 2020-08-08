#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long dp[31][31];
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    for (int i = 1; i <= 30; i++)
    {
        for (int j = 1; j <= 31; j++)
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1], cout << dp[i][j] << "  ";
        cout << endl;
    }
    cout << dp[30][30];
}