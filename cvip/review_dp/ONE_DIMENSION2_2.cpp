//2. Purchase tickets 
#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
int main()
{
    int n, t1[maxn], t2[maxn], t3[maxn], dp[maxn];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t1[i] >> t2[i] >> t3[i];
    dp[1] = 1;
    dp[2] = min(t1[1] + t1[2], t2[1]);
    dp[3] = min(min(dp[2] + t1[3], t3[1]), dp[1] + t2[2]);
    for (int i = 4; i <= n; i++)
        dp[i] = min(min(dp[i - 1] + t1[i], dp[i - 2] + t2[i - 1]), dp[i - 3] + t3[i - 2]);
    cout << dp[n];
}