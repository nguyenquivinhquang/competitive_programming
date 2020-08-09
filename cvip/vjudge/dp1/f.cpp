#include <bits/stdc++.h>
#define maxn 100
#define ll long long
using namespace std;
string a[maxn], temp;
int n, dp[maxn][maxn], testcase, res;
int main()
{
    freopen("/mnt/CODE/c++/cvip/vjudge/input.txt", "r", stdin);
    freopen("/mnt/CODE/c++/cvip/vjudge/out.txt", "w", stdout);
    cin >> testcase;
    n = 0;
    while (testcase--)
    {
        memset(dp, 0, sizeof(dp));
        cin >> a[0];
        n = a[0].length();
        for (int i = 1; i <= n - 1; i++)
        {
            cin >> a[i];
        }
        res = 0;
        for (int i = 0; i < n; i++)
            if (a[0][i] == '1')
                dp[0][i] = 1;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] == '1')
                    dp[i][j] = dp[i - 1][j] + 1;

        for (int i = 0; i < n; i++)
        {
            int le = 0, t = 1e9;
            for (int j = 0; j < n; j++)
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
        //debug
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << dp[i][j];
            cout << endl;
        }
        cout << res << "\n\n";
    }
}