#include <bits/stdc++.h>
#define ll long long
#define pp pair<int, int>
using namespace std;
const int N = 10005;
int x[N], n, y[N], dp[N][N];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    dp[1][1] = y[1];
    for (int i = 2; i <= n; i++){

        dp[i][0] = dp[i - 1][1] + x[i];
        dp[i][i] = dp[i - 1][i - 1] + y[i];
        for (int j = 1; j < i; j++)
            dp[i][j] = min(dp[i - 1][j - 1] + y[i], dp[i - 1][j + 1] + x[i]);
    }
    cout << dp[n][0];
}
