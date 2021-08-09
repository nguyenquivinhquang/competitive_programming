#include <bits/stdc++.h>
#define mod %
#define maxn 100005
#define ll long long
using namespace std;
ll a[maxn], vt[maxn];
ll n;
ll gcd(ll x, ll y)
{
    ll r;
    if (x < y)
        swap(x, y);
    while (y != 0)
        r = x mod y, x = y, y = r;
    return x;
}
ll Giang_Bae(ll m)
{
    ll max = 0, temp = a[m], t;
    for (ll i = m; i >= 1; i--)
    {
        temp = gcd(temp, a[i]);
        if (temp <= 1)
            return max;
        if (m != i)
            t = vt[m] - vt[i - 1];
        else
            t = vt[m] - vt[i - 1];
        if (temp * t > max)
            max = temp * t;
    }
    return max;
}
int process()
{
    int max = 0, m;
    for (int i = 1; i <= n; i++)
    {
        m = Giang_Bae(i);
        if (m > max)
            max = m;
    }
    if (max < n)
        max = n;
    return max;
}
int main()
{
    ll t, max = 1, m, temp;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        max = 0, a[0] = 0, n = 0, vt[0] = 0;
        cin >> m;
        for (ll j = 1; j <= m; j++)
        {
            cin >> temp;
            if (temp != a[n])
                n++, a[n] = temp;
            vt[n] = j;
        }
        cout << process() << endl;
    }
}