#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
void solve()
{
    ll n, lift[N], dp[N][N], student_out[N][N], student[N][N], angry_left[N], prefix[N], res = 1e9;
    int pos[N][N];
    reset(pos, 0), reset(student, 0), reset(angry_left, 0), reset(prefix, 0), reset(student_out, 0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> lift[i];
        prefix[i] = prefix[i - 1] + lift[i];
        angry_left[i] = angry_left[i - 1] * 2 + lift[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1e9;
        for (int j = 1; j <= n; j++)
        {
            ll total_angry = angry_left[j] - lift[j] + (prefix[n] - prefix[j])*i;
            student_out[i][j] = student_out[i - 1][pos[i - 1][j - 1]] * pow(2, j - pos[i - 1][j - 1]) + lift[j];
            dp[i][j] = total_angry - 2 * lift[j] - student_out[i][j];
            student[i][j] = student[i - 1][pos[i - 1][j - 1]] + lift[j];
            if (student[i][j] == prefix[n])
                res = min(res, dp[i][j]);
            pos[i][j] = dp[i][j] > dp[i][j - 1] ? pos[i][j - 1] : j;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    //cout << res << endl;
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