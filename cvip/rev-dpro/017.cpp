#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
#define reset(a,val) memset(a,val,sizeof(a))
#define modulo int(1e9+7)
#define endl '\n'
using namespace std;
int prefix[N], surfix[N], out[N], dp[N], n, remaining[N];
void solve()
{
    reset(surfix, 0), reset(prefix, 0), reset(dp, 0);
    int res = 1e9;
    cin >> n;
    for (int i = 1; i <= n ; i++)
    {
        cin >> out[i];
        prefix[i] = prefix[i - 1] * 2 + out[i];
        remaining[i] = remaining[i - 1] + out[i];
    }
    for (int i = n; i >= 1; i--)
        surfix[i] += surfix[i + 1] + out[i + 1];
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1e9;
        for (int j = i - 1; j >= 0; j--)
        {
            dp[i] = min(dp[i], (prefix[i] - prefix[j - 1]) * (i - j + 1) + surfix[i] - out[i]);
            //     cout << i << " & " << j << ": " << endl;
            //     cout << prefix[i] - remaining[j] * (i - j + 1) + surfix[i] - out[i] << endl;
        }
        res = min(res, dp[i]);
    }
    cout << res << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << dp[i] << " ";

}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}