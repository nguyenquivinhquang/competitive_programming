#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
int n, r, p, dp[1000001];
 
int brute(int n, int r, int p) {
    if (n == 1) return 0;
    if (dp[n] != -1) return dp[n];
 
    int ans = 1e18;
 
    for (int k = 2; k <= n; k++) {
        int cost = (k-1)*p;
        int biggest_seg = (n + k - 1)/k;
 
        ans = min(ans, cost + r + brute(biggest_seg, r, p));
    }
    return dp[n] = ans;
}
 
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    memset(dp, -1, sizeof(dp));
    cin >> n >> r >> p;
    cout << brute(n, r, p) << '\n';
 
    return 0;
}