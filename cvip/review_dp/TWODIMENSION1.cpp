//Binomial coefficients
#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;

int main()
{
    int n, m, dp[maxn][maxn];
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
    cout << dp[n][m];
}