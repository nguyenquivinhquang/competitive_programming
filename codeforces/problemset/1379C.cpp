#include <bits/stdc++.h>
#define N 200000
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

    ll n, m, res = 0, cur = 0;
    cur = res = 0;

    cin >> n >> m;
    pp a[m + 5];
    ll prefix[m + 5], b[m + 5];
    reset(a);
    reset(prefix);
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + m, cmp);

    for (int i = 1; i <= m; i++)
    {
        prefix[i] = prefix[i - 1] + a[i].first;
        b[i] = a[i].first;
    }
    for (int i = 1; i <= m; i++)
    {
        ll pos = lower_bound(b + 1, b + 1 + m, a[i].second, greater<int>()) - b;
        pos--;
        if (pos > n )
        {
            res = max(res, prefix[n]);
            continue;
        }

        cur = prefix[pos];
        ll nn = n - pos;
        if (pos < i)
            cur += a[i].first, nn--;
        cur += nn * a[i].second;
        res = max(res, cur);
    }
    cout << res << endl;
}
int main()
{
    fastio;
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}