//4. The Knight
#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;

int main()
{
    ll n, m, dp[maxn][maxn];
    cin >> n >> m;

    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (j - 1 > 0 && i - 2 > 0)
                dp[i][j] += dp[i - 2][j - 1];
            if (j - 2 > 0 && i - 1 > 0)
                dp[i][j] += dp[i - 1][j - 2];
        }
    cout << dp[n][m];
}