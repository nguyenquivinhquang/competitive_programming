#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long
const int N = 10009;

int n,k, dp[N], a[N], res = 0;

signed main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = -1e9;
    }
//    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= k && i - j >= 0; j++)
            dp[i] = max(dp[i], dp[i - j] + a[i]);
        res = max(res, dp[i]);
//        cout << dp[i] << " ";
    }
    cout << res;
}
