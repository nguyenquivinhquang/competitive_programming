#include <bits/stdc++.h>

using namespace std;
string a = "0", b = "0";
int dp[5002][5002];
int main()
{

    cin >> a;
    cin >> b;
    a='0'+a;
    b='0'+b;
    for (int i = 1; i <= a.length(); i++)
        dp[i][0] = i;
    for (int i = 1; i <= b.length(); i++)
        dp[0][i] = i;
    for (int i = 1; i <= a.length(); i++)
        for (int j = 1; j <= b.length(); j++)
        {
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
        }
    cout << dp[a.length()][b.length()];
}