#include <bits/stdc++.h>
#define maxn 120
#define ll long long
using namespace std;
char a[maxn][maxn], temp;
int n, m, dp[maxn][maxn], testcase, res;
int main()
{
   // freopen("/home/nguyenduyminhthong/Project/CVIP/quang/input.txt", "r", stdin);
    //freopen("/home/nguyenduyminhthong/Project/CVIP/quang/out.txt", "w", stdout);
    n = 0;
    while (1 != 0)
    {
        memset(dp, 0, sizeof(dp));
        cin >> n >> m;
        if (n == 0 && m == 0)
            return 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == '1')
                    a[i][j] = '0';
                else
                    a[i][j] = '1';
            }
        res = 0;
        for (int i = 0; i < m; i++)
            if (a[0][i] == '1')
                dp[0][i] = 1;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] == '1')
                    dp[i][j] = dp[i - 1][j] + 1;

        for (int i = 0; i < n; i++)
            for (int k = 0; k < m; k++)
            {
                int le = 0, t = 1e9;
                for (int j = k; j < m; j++)
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
        /*for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << dp[i][j];
            cout << endl;
        }*/
        cout << res << "\n";
    }
}