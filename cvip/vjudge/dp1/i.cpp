#include <bits/stdc++.h>
#define maxn 109
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
int testcase, n, m;
int a[maxn][maxn];
void reset()
{
    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 100; j++)
            a[i][j] = 1;
}
void fill(int x1, int y1, int x2, int y2)
{
    for (int i = x1; i <= x2; i++)
        for (int j = y1; j <= y2; j++)
            a[i][j] = 0;
}
int solve()
{
    int dp[maxn][maxn];
    memset(dp, 0, sizeof(dp));
    int res = 0;
    for (int i = 1; i <= n; i++)
        if (a[1][i] == 1)
            dp[1][i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 1)
                dp[i][j] = dp[i - 1][j] + 1;

    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= n; k++)
        {
            int le = 0, t = 1e9;
            for (int j = k; j <= n; j++)
                if (dp[i][j] != 0)
                {
                    t = min(t, dp[i][j]);
                    le++;
                    res = max(res, t * le);
                }
                else
                {
                    t = 1e9;
                    le = 0;
                }
        }
    return res;
}
int main()
{
    cin >> testcase;
    while (testcase--)
    {
        int x1, x2, y1, y2;
        cin >> n >> m;
        reset();
        for (int i = 1; i <= m; i++)
        {
            cin >> x1 >> y1 >> x2 >> y2;
            fill(x1, y1, x2, y2);
        }
        cout << solve() << endl;
    }
}