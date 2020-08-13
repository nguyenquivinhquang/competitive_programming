#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
#define maxn 100000000
using namespace std;
int n, k;
int main()
{
    fastio;
    cin >> n >> k;
    long long dp[k + 10], a[n + 10];
    memset(dp, 0, sizeof(dp) );
    for ( int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0] = 1;
    for (int i = 1; i <= k; i++)
        for (int j = 0; j <= n; j++)
        {
            if (j == 0) dp[i] = 0;
            else if (i - a[j] >= 0 )
            {
                dp[i] += dp[i - a[j]] ;
                dp[i] %= 1000000007;
            }
        }

    if (dp[k] == maxn) cout << -1;
    else cout << dp[k];

}