//Pascal's Triangle
#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;

int main()
{
    int dp[maxn][maxn], n;
    cin >> n;
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] += dp[i - 1][j-1] + dp[i - 1][j];
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

}