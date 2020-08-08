#include <bits/stdc++.h>
#define ll long long
#define modulo 1000000007
#define maxn 100001
using namespace std;
int n, m, a[maxn];
ll  lon[maxn], be[maxn], res = 0;
ll dp[maxn][101];
void step1()
{
    lon[1] = a[1], be[1] = a[1];
    if (a[1] == 0) lon[1] = m, be[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if ( a[i] == 0)
        {
            lon[i] = lon[i - 1] + 1;
            if (lon[i] > m) lon[i] = m;
            be[i]  = be[i - 1] - 1;
            if ( be[i] < 1 ) be[i] = 1;
        }
        else
        {
            lon[i] = a[i], be[i] = a[i];
        }
    }
}
void compute()
{
    for (int i = be[1]; i <= lon[1]; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= n ; i++)
        for (int j = be[i]; j <= lon[i]; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j + 1] + dp[i - 1][j - 1]) % modulo;

        }
    for (int i = be[n]; i <= lon[n]; i++)
        res = (res+dp[n][i]) % modulo;

}
int main()
{
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        lon[i] = 0, be[i] = 0;
    }

    step1();
    compute();
    cout << res;
}
