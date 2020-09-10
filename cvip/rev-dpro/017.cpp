#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
#define reset(a,val) memset(a,val,sizeof(a));
#define modulo int(1e9+7)
#define endl '\n'
using namespace std;
void solve()
{
    int n, s[N], dp[N], remaining[N], pre[N];
    reset(pre, 0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = n; i >= 1; i--)
        pre[i] += pre[i + 1] + s[i];
    for (int i = 1; i <= n; i++)
    {

        int angry = (pre[1] - pre[i + 1]) * (i - 1) + pre[i + 1];
        cout << angry << " ";
        // for (int j = i - 1; j >= 0; j--)
        // {

        // }
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << pre[i] << " ";
}
int main()
{
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        solve();
    }
}