#include <bits/stdc++.h>
#define maxn 1001
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
int main()
{
    fastio;
    int n, k;
    ll dp[maxn][maxn], a[maxn][maxn], res = -1e9;
    memset(dp, 0, sizeof(dp));
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            dp[i][j] = dp[i - 1][j] + a[i][j];
        }
    for (int i = k; i <= n; i++)
    {
        ll sum = 0;
        for (int j = 1; j <= n; j++)
            if (j <= k)
                sum += dp[i][j] - dp[i - k][j];
            else
            {
                res = max(res, sum);
                sum += dp[i][j] - dp[i - k][j];
                sum -= dp[i][j - k] - dp[i - k][j - k];
            }
        res = max(res, sum);
    }
    cout << res << endl;
}