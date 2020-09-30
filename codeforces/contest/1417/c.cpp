#include <bits/stdc++.h>
#define N 300005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;
map<int, int> trace;
int a[N], n, b[N], dp[N];
void solve()
{
    reset(b, -1);
    trace.clear();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = 1e9;
    }
    for (int i = 1; i <= n; i++)
    {
        int t = trace[a[i]];
        b[a[i]] = max(i - t, b[a[i]]);
        trace[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        b[a[i]] = max(n + 1 - trace[a[i]], b[a[i]]);
    for (int i = 1; i <= n; i++)
    {
        if (b[i] != -1)
            dp[b[i]] = min(i, dp[b[i]]);
    }
    for (int i = 2; i <= n; i++)
        dp[i] = min(dp[i], dp[i - 1]);
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == 1e9)
            dp[i] = -1;
        cout << dp[i] << " ";
    }
    cout << endl;
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