#include <bits/stdc++.h>
#define ll long long
#define maxn 200001
using namespace std;
int n, x, y, q, k, v;

vector<ll> a(maxn, 0);
ll ST[maxn * 4];

using namespace std;
void update(int node, int l, int r, int u, int v, int val)
{
    if (r < u || l > v)
        return;
    if (u <= l && r <= v)
    {
        ST[node] += val;
        return;
    }
    int mid = (l + r) / 2;
    update(node * 2, l, mid, u, v, val);
    update(node * 2 + 1, mid + 1, r, u, v, val);
}
ll get(int node, int l, int r, int pos)
{
    if (r < pos || l > pos)
        return 0;
    if (l == r)
        return ST[node];
    if (l <= pos && pos <= r)
    {

        int mid = (l + r) / 2;
        return get(node * 2, l, mid, pos) + get(node * 2 + 1, mid + 1, r, pos)+ST[node];
    }
}
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (q--)
    {
        cin >> k;
        if (k == 2)
        {
            cin >> x;
            cout << a[x] + get(1, 1, n, x) << endl;
        }
        else
        {
            cin >> x >> y >> v;
            update(1, 1, n, x, y, v);
        }
    }
}