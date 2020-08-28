#include <bits/stdc++.h>
#define N 1000000
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
void solve()
{
    int n, dp[N + 5], a[N + 5], res = 0, sum = 0;
    reset(dp, 0), reset(a, 0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        sum = max(sum, 0);
        res = max(res, sum);
    }
    sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        dp[i] = max(sum, dp[i - 1]);
    }
    sum = 0;
    for (int i = n; i >= 1; i--)
    {
        sum += a[i];
        res = max(res, sum + dp[i - 1]);
    }
    cout << res << endl;
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