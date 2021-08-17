#include <bits/stdc++.h>
#define int ll
#define ll long long
#define pp pair<int, int>

const int N = 500000;

using namespace std;

int n, s[N], t[N], dp[N];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i], s[n+i] = s[i];
    for (int i = 1; i <= n; i++) cin >> t[i], dp[i+n] = t[i], dp[i] = t[i];

    for (int i = 2; i <= 2 * n; i++) {
        dp[i] = min(dp[i-1] + s[i-1], dp[i]);
    }
    
    for (int i = 1; i <= n; i++) cout << min(dp[i], dp[i+n]) << "\n";
    
}
