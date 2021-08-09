#include <bits/stdc++.h>
#define maxn 1000000

using namespace std;
int a[101], dp[maxn][101], n = 0, m;
vector <int> res;
int main()
{
    cin >> m;
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
        n += a[i];
    }
    sort (a + 1, a + 1 + m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == a[j]) dp[i][j] = 1;
            else if ( i > a[j]) dp[i][j] = max(dp[i][j - 1], dp[i - a[j]][ j - 1]);
            else
                dp[i][j] = dp[i][j - 1];
        }
        if (dp[i][m] == 1) res.push_back(i);
    }
   

    cout << res.end() - res.begin() << endl;
    for (auto i : res)
        cout << i << " ";

}