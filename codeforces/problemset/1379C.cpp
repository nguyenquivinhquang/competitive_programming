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
ll get(ll val, pp a[], int size)
{
    ll l = 0, r = size + 1, mid;
    while (r - l > 1)
    {
        mid = (l + r) / 2;

        if (a[mid].first < val)
            r = mid;
        else
            l = mid;
    }
    return l;
}
void solve()
{

    // /pp a[N];
    ll n, m, res = 0, cur = 0;
    cur = res = 0;
    //reset(a);

    cin >> n >> m;
    pp a[m + 5];
    ll prefix[m + 5];
    reset(prefix);
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + m, cmp);
    for (int i = 1; i <= m; i++)
    {
        prefix[i] = prefix[i - 1] + a[i].first;
    }
    for (int i = 1; i <= m; i++)
    {
        ll pos = get(a[i].second, a, m);
        if (pos == 0)
        {
            res = max(res, a[i].first + a[i].second * (n - 1));
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