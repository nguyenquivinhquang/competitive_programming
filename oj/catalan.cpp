#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

int dp[N][N], n = 10, a[N], k; 
void init() {
    // dp[i][j] the number of paths that sum fron i -> n equal to j
    dp[2*n+1][0] = 1;
    for (int i = 2*n; i >= 0; i--) {
        for (int j = 0; j <= 2*n; j++) 
            dp[i][j] = dp[i+1][j+1] + dp[i+1][j-1];
    }

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    ll res = 0;
    init();
    for (int i = 0; i <= 2*n; i++) cin >> a[i];
    for (int i = 1; i <= 2*n; i++) {
        if (a[i] <= a[i-1] ) continue;
        res += dp[i+1][a[i]-2];
    }
    cout << res+1 << "\n";

    cin >> k; k--;
    int cur = 0;
    cout << "0 ";
    for (int i = 1; i <= 2*n; i++) {
        if (cur == 0) {
            cur++;
        } else
        if (k >= dp[i+1][cur-1] ){
            k -=  dp[i+1][cur-1];
            cur++;
        }
        else cur--;
        cout << cur << " ";
    }
}