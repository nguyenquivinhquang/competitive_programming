#include <bits/stdc++.h>
#define N 1000
#define ll long long
#define pp pair<ll, ll>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;

bool cmp(pp x, pp y)
{
    if (x.first != y.first)
        return x.first > y.first;
    return x.second > y.second;
}
void solve()
{
    pp a[N];
    ll n, m, res, cur, count[N];
    memset(count, 0, sizeof(count));

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + m, cmp);

    
    for (int i = 1; i <= m; i++)
        cout << a[i].first << " " << a[i].second << endl;
    cout << endl;
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