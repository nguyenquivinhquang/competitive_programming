#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
#define maxn 100000000
using namespace std;
int n, k;
int main()
{
    fastio;
    cin >> n >> k;
    int dp[k + 10], a[n + 10];
    for ( int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0] = 0;
    for (int i = 1; i <= k; i++)
        for (int j = 0; j <= n; j++)
        {
            if (j == 0) dp[i] = maxn;
            else if (i - a[j] != maxn && i >= a[j])
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }

    if (dp[k] == maxn) cout << -1;
    else cout << dp[k];

}