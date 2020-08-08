//8. Route bug
#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int main()
{

    int n, m, dp[maxn][maxn], a[maxn][maxn];
    vector<char> trace;
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    dp[1][0] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
    int i = n, j = m;
    while (1)
    {
        if ((dp[i - 1][j] == dp[i][j] - a[i][j]) && i - 1 > 0)
        {
            trace.push_back('D');
            i -= 1;
        }
        else if ((dp[i][j - 1] == dp[i][j] - a[i][j]) && j - 1 > 0)
        {
            trace.push_back('R');
            j -= 1;
        }
        if (i == 1 && j == 1)
            break;
    }
    reverse(trace.begin(), trace.end());
    cout << dp[n][m] << endl;
    for (auto v : trace)
        cout << v << " ";
}