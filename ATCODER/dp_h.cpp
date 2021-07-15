#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1009;

using namespace std;
int h, w, dp[N][N];

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    
    char c;
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> c;
            if (c == '#') {
                dp[i][j] = 0;
                continue;
            }
            if (i == 1 && j == 1) dp[i][j] = 1;
            else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    cout << dp[h][w];
}
