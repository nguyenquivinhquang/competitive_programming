#include <bits/stdc++.h>
#define maxn 100001
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;
void solve()
{
    int n, m, a[maxn];
    ll res = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] % m != 0)
            res += m - (a[i] % m);
    }
    cout << res << endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}