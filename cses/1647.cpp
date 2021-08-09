#include <bits/stdc++.h>
#define ll long long
#define maxn 200001
using namespace std;
int n, x, y, q;
vector<ll> a(maxn, 0);
ll ST[maxn * 4];
void build(int id, int l, int r)
{
    if (l == r)
    {
        ST[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    ST[id] = min(ST[id * 2], ST[id * 2 + 1]);
}
ll get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return 10000000000;
    }
    if (u <= l && r <= v)
    {
        return ST[id];
    }
    int mid = (l + r) / 2;

    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
        ST[l] = val;
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    ST[id] = min(ST[id * 2], ST[id * 2 + 1]);
}
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while ((q--))
    {
        cin >> x >> y;
        cout << get(1, 1, n, x, y) << "\n";
    }
}