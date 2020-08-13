#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> a;
int n, t;
ll res = 9000000000000000000;
ll compute(ll seconds)
{
    ll products = 0;
    for (auto i : a)
        products += seconds / i;
    return products;
}
int main()
{
    int temp;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    ll l = 1, r = 1000000000000000000, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        ll products = compute(mid);
        if (abs(products) < t)
            l = mid + 1;
        else
        {
            res = min(res, mid);
            r = mid - 1;
        }
    }
    cout << res;
}