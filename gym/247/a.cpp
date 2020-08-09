#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;

double dp[51][51];

void init()
{
    for (int n = 1; n <= 50; n++)
    {
        dp[n][1] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                dp[n][j] += dp[n][i] * 1.0 / (n - i + 1);
            }
        }
    }

}

void solve()
{
    cout << fixed << setprecision(6);
    int n, m;
    cin >> n >> m;
    if (n == 1)
    {
        cout << 1.0 << ' ';
    }
    else
    {
        cout << (1.0 / 2) << ' ';
    }

    if (m == 1)
    {
        cout << 1.0 << '\n';
    }
    else
    {
        cout << 1.0 * (m - 1) / m << '\n';
    }
}

int main()
{
    init();

    fastio
    int testcase;
    cin >> testcase;
    for (int i = 1; i <= testcase; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

}