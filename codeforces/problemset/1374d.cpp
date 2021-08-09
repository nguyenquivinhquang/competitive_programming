#include <map>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#define ll long long
#define maxn 200001
using namespace std;
int main()
{
    ll testcase, n, k, a[maxn];
    cin >> testcase;
    while (testcase--)
    {

        ll res = 0, mod;
        map<ll, ll> trace;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++)
            if (a[i] % k != 0)
            {
                mod = (k - a[i] % k) % k;
                trace[mod]++;
            }
        for (auto v : trace)
        {
            ll t = k * (v.second - 1);
            t += v.first;
            res = max(res, t);
        }
        if (res != 0)
            res++;
        cout << res << endl;
    }
}