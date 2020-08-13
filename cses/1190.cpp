#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;
struct cmp
{
    ll l, r, sum, max_seg;
};

ll n, m, x, k, a[maxn];
cmp it[maxn * 4];
void build(int node, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        it[node].l = val;
        it[node].r = val;
        it[node].sum = val;
        it[node].max_seg = val;
        return;
    }

    int mid = (l + r) / 2;
    build(node * 2, l, mid, pos, val);
    build(node * 2 + 1, mid + 1, r, pos, val);
    it[node].l = max(it[node * 2].l, it[node * 2].sum + it[node * 2 + 1].l);
    it[node].r = max(it[node * 2 + 1].r, it[node * 2 + 1].sum + it[node * 2].r);
    it[node].max_seg = -10000000000;
    it[node].sum = it[node * 2 + 1].sum + it[node * 2].sum;
    vector<ll> temp({it[node].l, it[node].r, it[node * 2].max_seg, it[node * 2 + 1].max_seg, it[node * 2].r + it[node * 2 + 1].l});
    for (auto c : temp)
        it[node].max_seg = max(it[node].max_seg, c);
}
void reset()
{
    cmp temp = {-1000000000000, -1000000000000, -1000000000000, -1000000000000};
    for (int i = 1; i <= 4 * n; i++)
        it[i] = temp;
}
int main()
{
    cin >> n >> m;
    reset();
    int temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        build(1, 1, n, i, temp);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> k >> x;
        build(1, 1, n, k, x);
        cout << it[1].max_seg << endl;
    }
}