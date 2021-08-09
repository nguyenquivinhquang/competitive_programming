#include <bits/stdc++.h>
#define maxn 5001
using namespace std;
long long n, dp[maxn][maxn], x[maxn];
long long sum = 0;
void debug()
{
    cout << endl << "debug: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    //freopen("testcase.txt", "r", stdin);
    memset(dp, sizeof(dp), 0);
    cin >> n ;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = n-1; i >= 0; i--)
        for (int j = 0; j < n; j++)
            if (i == j)
            {
                dp[i][j] = x[i];
                sum += x[i];
            }
            else dp[i][j] = max(x[i] - dp[i + 1][j], x[j] - dp[i][j - 1]);
    cout << (sum + dp[0][n-1]) / 2;
    debug();
}