#include <bits/stdc++.h>
#define maxn 100
#define ll long long
using namespace std;
ll dp[maxn], a[maxn], n, l, res = 0;
int main()
{
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = i, sum = a[i];
        dp[i] = max(l - a[i], dp[i - 1]);
        while (sum+a[j-1] <= l && j >= 1)
        {
            j--;
            sum += a[j];
            dp[i] = min(dp[i], max(dp[j-1], l - sum));
        }
    }
    for (int i=1; i<=n;i++)
    cout << dp[i] << endl;

}