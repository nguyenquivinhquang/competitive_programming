//7. Turtle 
#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;


int main()
{

    int n, m, dp[maxn][maxn], a[maxn][maxn];
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    dp[1][0] = 0;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];

    cout << dp[n][m];
}