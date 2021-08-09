#include <bits/stdc++.h>
#define N 250
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
bool cmp(int x, int y)
{
    return x > y;
}
void solve()
{
    vector<int> x, y, z;
    int r, g, b, temp, res = 0;
    int dp[N][N][N];
    reset(dp);
    x.push_back(1e9), y.push_back(1e9), z.push_back(1e9);
    cin >> r >> g >> b;
    for (int i = 1; i <= r; i++)
    {
        cin >> temp;
        x.push_back(temp);
    }
    for (int i = 1; i <= g; i++)
    {
        cin >> temp;
        y.push_back(temp);
    }
    for (int i = 1; i <= b; i++)
    {
        cin >> temp;
        z.push_back(temp);
    }

    sort(x.begin(), x.end(), cmp), sort(y.begin(), y.end(), cmp), sort(z.begin(), z.end(), cmp);
    x[0] = y[0] = z[0] = 0;
    for (int i = 0; i <= r; i++)
        for (int j = 0; j <= g; j++)
            for (int k = 0; k <= b; k++)
            {
                if (i && j)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + x[i] * y[j]);
                if (i && k)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + x[i] * z[k]);
                if (j && k)
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + z[k] * y[j]);
                res = max(res, dp[i][j][k]);
            }

    cout << res << endl;
}
int main()
{
    solve();
    fastio;
}