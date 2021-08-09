#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 1004;
int n, m, dp[N][N], a[N][N], D[N], L[N], R[N], top;
ll res = 0;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            if (a[i][j] == 1) dp[i][j] = dp[i - 1][j] + 1;
        }
//    cout << dp[9][3];
    for (int i = 1; i <= n; i++) {
        D[0] = 0, top = 0;
        for (int j = 1; j <= m; j++) {
            while (top > 0 && dp[i][D[top]] >= dp[i][j]) top--;
            L[j] = D[top] + 1;
            D[++top] = j;
        }
        D[0] = m + 1, top = 0;
        for (int j = m; j  >= 1; j--) {
            while (top > 0 && dp[i][D[top]] >= dp[i][j]) top--;
            R[j] = D[top] - 1;
            D[++top] = j;
        }
        for (int j = 1; j <= m; j++) {
            res = max(res, (R[j] - L[j] + 1) * dp[i][j]);
//            cout << i << " " << j << ": " << L[j] << " " << R[j] << "\n";
        }
    }
    cout << res;
}
