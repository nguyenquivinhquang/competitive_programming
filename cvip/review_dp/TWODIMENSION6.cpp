//6. Escape Attempt
#include <bits/stdc++.h>
#define maxn 1001
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;

int main()
{
    ll n, m, a[maxn][maxn], dp[maxn][maxn];
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j])
            {
                dp[i][j] += a[i - 1][j] ? dp[i - 1][j] : 0;
                dp[i][j] += a[i][j - 1] ? dp[i][j - 1] : 0;
            }
    if (dp[n][m])
        cout << dp[n][m];
    else cout << "Impossible";
}