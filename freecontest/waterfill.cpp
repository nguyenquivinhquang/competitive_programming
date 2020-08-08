#include <bits/stdc++.h>
#define N 200000
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
ll a[N], n, k;
bool check(ll t)
{
    ll debt = 0, v = k * t;
    for (int i = 1; i <= n; i++)
    {
        if (v + debt < a[i])
            return false;
        else
            debt = v + debt - a[i];
    }
    return true;
}
bool check2(ll t)
{
    ll debt = 0, v = k * t;
    for (int i = 1; i < n; i++)
    {
        if (v + debt < a[i])
            debt = 0;
        else
            debt = v + debt - a[i];
    }
    if (v + debt < a[n])
        return false;
    return true;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    ll l = 0, r = 1e9 + 7, mid, res = 1e9 + 7;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check2(mid) == true)
        {
            res = min(res, mid);
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << res << " ";
    l = 0, r = 1e9 + 7, mid, res = 1e9 + 7;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(mid) == true)
        {
            res = min(res, mid);
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << res;
}