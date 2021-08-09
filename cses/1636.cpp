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

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            if (j >= a[i])
            {
                dp[j] += dp[j - a[i]];
                dp[j] %= 1000000007;
            }
    cout << dp[k];

}