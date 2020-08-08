#include <bits/stdc++.h>
#define ll long long
#define maxn 100006
using namespace std;
double pre[maxn];
double a[maxn], n;
double res = 1000000000000000000.0;
void compute_g()
{
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
        pre[i] = a[i] + pre[i - 1];
}
double distance(ll x, ll y)
{
    double dt = 0.0;
    dt += (y - x) * (y - x);
    dt += (pre[x] - pre[y]) * (pre[x] - pre[y]);
    return (dt);
}
void closet(ll l, ll r)
{
    double d;
    if (l >= r)
        return;
    ll mid = (l + r) / 2;
    closet(l, mid - 1);
    closet(mid + 1, r);
    for (int i = mid; i >= l; i--)
    {
        d = distance(i, mid) + 0.0;
        if (d < res && i != mid)
            res = d;
        for (int j = mid; j <= r; j++)
            if (i != j)
            {
                d = distance(i, j);
                if (d <= res)
                    res = d;
                if (((j - i) * (j - i)) > res)
                    break;
                if ((j-mid)>700) break;
            }
        if (mid - i > 700)
            break;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    compute_g();
    closet(1, n);
    ll r = res;
    cout << r;
}