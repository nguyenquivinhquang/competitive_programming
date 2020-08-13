#include <bits/stdc++.h>
#define ll long long
#define maxn 200001
using namespace std;
int n, x, y;
vector<ll> a(maxn, 0), prefix(maxn, 0), sum(maxn, 0);
ll ST[maxn * 4];
void build(int id, int l, int r)
{
    if (l == r)
    {
        ST[id] = sum[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    ST[id] = max(ST[id * 2], ST[id * 2 + 1]);
}
void debug()
{
    for (int i = 1; i <= 50; i++)
        cout << ST[i] << " ";
}
ll get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return -10000000000;
    }
    if (u <= l && r <= v)
    {
        return ST[id];
    }
    int mid = (l + r) / 2;

    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
int main()
{
    int temp;
    ll res = -100000000000000000;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
        sum[i] = -(prefix[i] - a[i]);
    }

    build(1, 1, n);
    //debug();
    for (int i = x; i <= n; i++)
    {
        ll temp = get(1, 1, n, i - y + 1, i - x + 1);
        int l = i - y + 1, r = i - x + 1;
        if (l < 1)
            l = 1;
        res = max(res, prefix[i] + get(1, 1, n,l,r));
    }
    cout << res;
}