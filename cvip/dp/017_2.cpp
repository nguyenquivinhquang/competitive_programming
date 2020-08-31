#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
void solve()
{
    int n, lift[N], dp[N][N], prefix[N], out[N][N], pos[N][N], res = 1e9;
    cin >> n;
    reset(dp, 0), reset(prefix, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> lift[i];
        prefix[i] = prefix[i - 1] + lift[i];
        if (lift[i] != 0)
            pos[0][i] = i;
        else
            pos[0][i] = pos[0][i - 1];
    }
    for (int i = 1; i <= 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int min_pos = pos[i - 1][j - 1];
            int remaining = prefix[j] - out[i - 1][min_pos] - lift[j];
            dp[i][j] = dp[i - 1][min_pos] + remaining * pow(2, j - min_pos - 1) + prefix[n] - prefix[j];
            out[i][j] += lift[j];
            // if (dp[i][j] > dp[i][j - 1] && j - 1 > 0)
            // {
            //     dp[i][j] = dp[i][j - 1];
            //     pos[i][j] = pos[i][j - 1];
            // }
            // else
            //     pos[i][j] = j;
            cout << dp[i][j] << " ";
        }
        res = min(res, dp[i][n]);
        cout << endl;
    }

    cout << res << endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}