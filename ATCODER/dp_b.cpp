#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1000000;
int h[N], dp[N], n, k;
signed main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin.exceptions(cin.failbit);
    cin >>  n >> k;
    for (int i = 1; i <= n; i++){
        cin >> h[i];
        dp[i] = 1e9;
    }
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k && i - j > 0; j++) {
            dp[i] = min(dp[i], dp[i- j] + abs(h[i] - h[i - j]));
        }
    }

    cout << dp[n];
}
