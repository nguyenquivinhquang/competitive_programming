#include <bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;
int n, k;
vector<ll> a(maxn, 0), prefix;
bool check(ll t)
{
    ll Max = -1000000, pre = 0, l = 0;
    for (int i = 1; i <= k; i++)
    {
        auto pos = lower_bound(prefix.begin() + l + 1, prefix.end(), pre + t) - prefix.begin();
        if (pos == n + 1)
            pos--;
        while (pos - 1 > l && prefix[pos] - prefix[l] > t)
            pos--;
        if (i == k)
            pos = n;
        Max = max(Max, prefix[pos] - prefix[l]);
        l = pos, pre = prefix[pos];
    }
    return Max <= t;
}
int main()
{
    cin >> n >> k;
    ll temp;
    prefix.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix.push_back(prefix[i - 1] + a[i]);
    }
    ll mid, l = 1, r = 1e18;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(mid) == true)
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << l;
}