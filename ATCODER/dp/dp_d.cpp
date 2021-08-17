#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

long long n, dp[100001], w[N], W, v[N];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin  >> n >> W;
    for (int i = 1; i <= n; i++ ) cin >> w[i] >> v[i];
    for (int i = 1; i <= n; i++)
        for (int j = W; j >= 1; j--)
            if (w[i] <= j)
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout << dp[W];
}
