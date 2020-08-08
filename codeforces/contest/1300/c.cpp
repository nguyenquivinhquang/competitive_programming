#include <bits/stdc++.h>
#define maxn 100000 + 5
#define mod %

#define ll long long
using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll a[n + 5], res = 0, pre[n + 5], surf[n + 5], pos = -1;
    for (long long i = 1; i <= n; i++)
        cin >> a[i];
    pre[1] = ~a[1];
    for (int i = 2; i <= n; i++)
        pre[i] = (pre[i - 1] & (~a[i]));
    surf[n] = ~a[n];
    for (int i = n - 1; i >= 1; i--)
        surf[i] = (~a[i]) & (surf[i + 1]);
    res = a[1] & surf[2];
    int t = a[n] & pre[n - 1];
    if ((a[n] & pre[n - 1]) > res)
    {
        res = a[n] & pre[n - 1];
        pos = n;
    }
    for (int i = 2; i < n; i++)
    {
        ll t = (a[i] & (pre[i - 1])) & (surf[i + 1]);
        if (t > res)
        {
            res = t;
            pos = i;
        }
    }
    //cout << res << endl;
    if (pos != -1)
        swap(a[1], a[pos]);
    for (long long i = 1; i <= n; i++)
        cout << a[i] << " ";
}