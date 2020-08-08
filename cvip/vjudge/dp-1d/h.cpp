#include <bits/stdc++.h>
#define ll long long
#define N 20000
#define reset                        \
    for (int i = 1; i <= m; i++)     \
        for (int j = 0; j <= n; j++) \
    dp[i][j] = 1e8
using namespace std;
void solve()
{
    int n, temp, res = 0, price, m = N;
    bool check = false;
    int a[101], dp[N+7][101+7];
    cin >> price >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    reset;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == a[j])
                dp[i][j] = 1;
            else if (i - a[j] > 0 && dp[i - a[j]][j - 1] < 1e8)
                dp[i][j] = min(dp[i][j - 1], dp[i - a[j]][j - 1] + 1);
            else
                dp[i][j] = dp[i][j - 1];
        }
        if (dp[i][n] < 1e8 && i >= price)
        {
            cout << i << " " << dp[i][n] << endl;
            return;
        }
    }
}
int main()
{
    //freopen("out.txt", "w", stdout);
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}