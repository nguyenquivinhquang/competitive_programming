#include <bits/stdc++.h>
#define el '\n'
#define mod &
#define ll long long
using namespace std;

int main()
{
    ll testcase;
    cin >> testcase;
    while (testcase--)
    {
        ll n, i, j, sum = 0, c = 0;
        cin >> n;
        ll a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        ll l = -10000000000, r = 0;
        for (i = 0; i < n - 1; i++)
        {
            r += a[i];
            if (r > l)
                l = r;
            if (r < 0)
                r = 0;
        }
        ll l1 = -10000000000, r1 = 0;
        for (i = 1; i < n; i++)
        {
            r1 += a[i];
            if (r1 > l1)
                l1 = r1;
            if (r1 < 0)
                r1 = 0;
        }
        if (l1 > l)
            l = l1;
        if (sum > l)
            cout << "YES"<<el;
        else
            cout << "NO"<<el;
    }
}