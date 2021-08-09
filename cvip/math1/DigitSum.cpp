#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll a[20];
ll pre[20];

void tach_so(string n)
{
    ll t = 1;
    pre[n.length()] = 0;
    for (ll i = 0; i < n.length(); i++)
        a[i] = n[i] - 48;
    for (ll i = n.length() - 1; i >= 0; i--)
    {
        pre[i] = (n[i] - 48) * t + pre[i + 1];
        t = t * 10;
    }
}
ll sumx(ll x) /// tong tu 0 toi x;
{
    ll sum = 0;
    for (ll i = 1; i <= x; i++)
        sum += i;
    return sum;
}

ll x10(ll x)
{
    ll res = 1;
    for (ll i = 1; i < x; i++)
        res = res * 10;
    return res;
}

ll sum_cs(ll vt, ll l)
{
    ll sum = sumx(a[vt] - 1);
    ll t = x10(l - vt);
    sum = sum * t + 45 * a[vt] * (t / 10) * (l - vt - 1) + a[vt];
    return sum;
}
ll Hoai_Thuong(string n)
{
    ll sum = 0;
    for (ll i = 0; i < n.length(); i++)
    {
        sum = sum + sum_cs(i, n.length()) + a[i] * pre[i + 1];
    }
    return sum;
}
ll ngu_nguoi(string a)
{
    ll sum = 0;
    for (ll i = 0; i < a.length(); i++)
        sum += a[i] - 48;
    return sum;
}
int main()
{
    ll sum1 = 0;
    ll sum2 = 0;
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        string n, m;
        cin >> n;
        tach_so(n);
        ll sum1 = Hoai_Thuong(n);
        cin >> m;
        tach_so(m);
        ll sum2 = Hoai_Thuong(m);
        cout << sum2 - sum1 + ngu_nguoi(n) << endl;
    }
}