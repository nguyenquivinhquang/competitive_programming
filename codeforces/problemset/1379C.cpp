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
    if (y.second > x.second)
        return false;
    if (y.second < x.second)
        return true;
    return y.first < x.first;
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
    cur = res = a[1].first + a[1].second * (n - 1);
    count[1] = n;
    int start = 1;
    for (int i = 2; i <= m; i++)
    {
        double t = 0 - (a[start].first - a[start].second - (a[i].first - a[i].second));
        t /= (a[start].second - a[i].second);
        t = ceil(t) - 1;
        if (t <= 1)
            continue;
        if (count[start] > t)
        {
            count[start] -= t;
            count[i] += t;
            cur -= a[start].second * t;
            cur += a[i].first + (t - 1) * a[i].second;
            res = max(res, cur);
        }
        else
        {
            t = count[start];
            count[i] += t;
            cur -= a[start].second * t + a[start].first;
            cur += a[i].first + (t - 1) * a[i].second;
            start++;
            res = max(res, cur);
        }
    }
    cout << res;
    cout << endl;
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