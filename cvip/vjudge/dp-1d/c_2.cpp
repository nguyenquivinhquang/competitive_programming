#include <bits/stdc++.h>
#define maxn 100000
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
void solve()
{
    int n, a[maxn], dp[maxn], dec = 0, inc = 0, b[maxn];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= n; j++)
        cin >> b[j];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 1; j--)
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j]);
        dp[i] += b[i];
        inc = max(inc, dp[i]);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 1; j--)
            if (a[i] < a[j])
                dp[i] = max(dp[i], dp[j]);
        dp[i] += b[i];
        dec = max(dec, dp[i]);
    }
    if (inc >= dec)
        printf("Increasing (%d). Decreasing (%d).\n", inc, dec);
    else
        printf("Decreasing (%d). Increasing (%d).\n", dec, inc);
}
int main()
{
    int testcase;
    cin >> testcase;
    for (int i = 1; i <= testcase; i++)
    {
        printf("Case %d. ", i);
        solve();
    }
}