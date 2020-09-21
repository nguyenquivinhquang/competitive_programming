#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
int main()
{
    int n, x, bd = 0, res = 0;

    ll p[N], dp[N], prefix[N];
    cin >> n >> x;
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
    cout << res << endl;
}