#include <bits/stdc++.h>
#define maxn 101
#define ll long long
using namespace std;
ll dp[maxn], l, k, res = 0;
int main()
{
    
    cin >> l >> k;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 0;
    dp[k] = 1;
    for (int i = 3; i <= l; i++)
    {
        if (dp[i - 2] > 0)
            dp[i] += dp[i - 2];
        if (i - k - 1 > 0)
            if (dp[i - k - 1] > 0)
                dp[i] += dp[i - k - 1];
    }
    for (int i = 1; i <= l; i++)
        res += dp[i];
    printf("%lld\n",res);
}