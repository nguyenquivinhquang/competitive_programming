#include <bits/stdc++.h>
#define modulo 1000000007
using namespace std;
int dp[200000];
int main()
{
    memset(dp, 0, sizeof(dp));
    int n;
    cin >> n;
    int lim = n * (n + 1) / 2;
    if (lim % 2)
    {
        cout << 0 << endl;
        return 0;
    }
    lim = lim / 2;
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = lim; j >= i; j--)
        {
            dp[j] += dp[j - i];
            dp[j] %= modulo;
        }
    }
    cout << dp[lim] << endl;
}
