//Calculator
#include <bits/stdc++.h>
#define ll long long
#define maxn 1000000
using namespace std;

int main()
{
    ll dp[maxn], n;
    int step;
    cin >> n;
    dp[1] = dp[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2]);
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3]);
        dp[i]++;
    }
    cout << dp[n];
}