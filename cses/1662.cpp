#include <bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;
ll a[maxn], n, temp, sum[maxn], res = 0;
map<ll, ll> modulo;
ll mod(ll x, ll m)
{
    if (x >= 0)
        return x % m;
    x = -x;
    if (x % m == 0)
        return 0;
    return (x / m + 1) * m - x;
}

int main()
{
    memset(a, 0, sizeof(a));
    memset(sum, 0, sizeof(sum));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i - 1];
        modulo[mod(sum[i], n)]++;
        ll pd = mod(mod(-n + mod(sum[i], n), n) + mod(a[i], n), n);
        res += modulo[pd];
    }

    cout << res;
}