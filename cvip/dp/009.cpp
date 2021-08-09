#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
int main()
{
    ll n, m, dp[N + 10][N + 10], a[N + 10][N + 10], res = 0;
    reset(dp, 0), reset(a, 0);
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = j; k >= 0; k--)
            {
                dp[i][j] = max(a[i][k] + dp[i - 1][j - k], dp[i][j]);
            }
            
        }

    }
    cout << dp[n][m];
}