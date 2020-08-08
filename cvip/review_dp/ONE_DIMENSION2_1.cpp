//1. Carnations 
#include <bits/stdc++.h>
#define maxn 101
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
int main()
{
    int n, a[maxn], dp[maxn];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    dp[1] = dp[2] = a[2] - a[1];
    for (int i = 3; i <= n; i++)
        dp[i] = min(dp[i - 1], dp[i - 2]) + a[i] - a[i - 1];
    cout << dp[n];
}