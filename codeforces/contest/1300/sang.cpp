#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n, pre[100], suf[100], a[100];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = (i != 1) ? (pre[i - 1] & (~a[i])) : ~a[i];
    }
    for (int i = n; i >= 1; i--)
        suf[i] = (i != n) ? (suf[i + 1] & (~a[i])) : ~a[i];
    ll res = 0, pos = 0;
    for (int i = 2; i < n; i++)
    {
        ll x = ((pre[i - 1] & a[i]) & suf[i + 1]);
        if (x > res)
        {
            res = x, pos = i;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << pre[i] << " ";
    if (n >= 2)
    {
        if ((a[1] & suf[2]) > res)
            res = (a[1] & suf[2]), pos = 1;
        if ((a[n] & pre[n - 1]) > res)
            res = (a[n] & pre[n - 1]), pos = n;
    }
    cout << endl;
    if (pos != 0)
        cout << a[pos] << " ";
    for (int i = 1; i <= n; i++)
        if (i != pos)
            cout << a[i] << " ";
    return 0;
}