#include <bits/stdc++.h>
#define ll long long
#define pp pair<int, int>
#define int long long
using namespace std;
const int N = 1300;

int a[N], dp[N + 2][N + 2], n;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(dp, 1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++) {
            if (a[i] > 100 && j > 0)
                dp[i][j] = min(dp[i - 1][j - 1] + a[i], dp[i - 1][ j + 1]);
            else dp[i][j] = min(dp[i - 1][j] + a[i], dp[i - 1][j + 1]);
                 }
    int res = dp[n][0];
    for (int i = 1; i <= n; i++)
        res = min(res, dp[i][n]);
    cout << res;
}
