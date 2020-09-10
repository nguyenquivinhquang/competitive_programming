#include <bits/stdc++.h>
#define N 105
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
#define reset(a,val) memset(a,val,sizeof(a));
#define modulo int(1e9+7)
#define endl '\n'
#define MaxValue 100005
using namespace std;

int main()
{
    fastio;
    int n, h[N], s[N], k[N], x, dp[N][MaxValue], count[N], res = 0;
    memset(dp, 0, sizeof(dp));
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> h[i]; //price
    for (int i = 1; i <= n; i++)
        cin >> s[i]; // pages
    for (int i = 1; i <= n; i++)
        cin >> k[i]; // copies
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= min(x, h[i]); j++)
        {
            dp[i][j] = dp[i - 1][j];
            for (int c = 0, p = 0, t = 0; c <= x && t <= k[i]; c += h[i], p += s[i], t++)
            {
                if (j - c < 0)
                    break;
                dp[i][j] = max(dp[i][j], dp[i - 1][j - c] + p);
            }
            res = max(res, dp[i][j]);

        }
    cout << res << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= x; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
}