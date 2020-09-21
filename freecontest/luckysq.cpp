#include <bits/stdc++.h>
#define N 1000005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
ll n, m, arr[1001][1001], k;
ll countSubsquare(ll X)
{
    ll dp[n + 1][m + 1];

    memset(dp, 0, sizeof(dp));

    for (ll i = 0; i < n; i++)
    {

        for (ll j = 0; j < m; j++)
        {

            dp[i + 1][j + 1] = arr[i][j];
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {

            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
    ll cnt = 0;
    for (ll i = 1; i <= n; i++)
    {

        for (ll j = 1; j <= m; j++)
        {
            ll lo = 1;
            ll hi = min(n - i, m - j) + 1;
            bool found = false;

            while (lo <= hi)
            {
                ll mid = (lo + hi) / 2;
                ll ni = i + mid - 1;
                ll nj = j + mid - 1;
                ll sum = dp[ni][nj] - dp[ni][j - 1] - dp[i - 1][nj] + dp[i - 1][j - 1];

                if (sum >= X)
                {
                    if (sum == X)
                    {
                        found = true;
                    }

                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            if (found == true)
            {
                cnt++;
            }
        }
    }
    return cnt;
}
void solve()
{
    int x, bd = 0, res = 0;

    ll p[N], dp[N], prefix[N];
    x = k;
    reset(prefix, 0);
    p[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        prefix[i] = prefix[i - 1] + p[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        ll len = prefix[i - 1] - prefix[bd] + p[bd];
        len = len + p[i] * (i - bd);
        dp[i] += (len * 2 + p[i] * 2);
        while (dp[i] > x)
        {
            len = prefix[i] - prefix[bd + 1] + p[bd + 1];
            len = len + p[bd] * (i - bd);
            dp[i] -= (len * 2 + p[bd] * 2);
            bd++;
        }
        if (dp[i] == x)
            res++;
    }
    cout << res*2 << endl;
}
int main()
{
    ll k, p[1005];
    cin >> n >> k;
    if (n <= 1000)
    {
        m = n;
        for (ll i = 0; i < n; i++)
            cin >> p[i];
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j <= n; j++)
                arr[i][j] = p[i] + p[j];
        cout << countSubsquare(k) << endl;
    }
    else
        solve();
}