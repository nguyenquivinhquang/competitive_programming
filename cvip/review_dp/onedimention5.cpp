//5. Paid ladder 
#include <bits/stdc++.h>
#define maxn 102
using namespace std;
int dp[maxn], a[maxn], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = 99999999;
    }
    dp[n + 1] = 99999999, a[n + 1] = 99999999;
    for (int i = 1; i <= n + 1; i++)
        for (int j = i - 1; j >= 0; j--)
            dp[i] = min(dp[i], dp[j] + a[i - j]);
    cout << dp[n + 1];
}