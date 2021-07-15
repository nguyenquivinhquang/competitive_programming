#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 5000;

using namespace std;

long double p[N], dp[N][N];
int n;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i; j++) {
           
            dp[i][j] = dp[i - 1][j] * (1 - p[i]); // current state is tail
            if (j > 0 ) dp[i][j] += dp[i - 1][j - 1] * p[i]; // current state is tail
        }
    long double res = 0.0;
    for (int i = 1; i <=n; i++) 
    if (i > n - i) res += dp[n][i];
    cout <<  fixed << setprecision(15) <<res;
}
