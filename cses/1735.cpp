#include <bits/stdc++.h>
#define maxn 2000
#define ll long long
using namespace std;
struct quangcute
{
    ll val, q1, q2;
};
ll n, a[maxn], m;
quangcute it[maxn * 4];
void down(int node, int l, int r)
{
    int mid = (l + r) / 2;
    if (it[node].q2 != 0)
    {
        int t = it[node].q2;
        it[node * 2 + 1].q1 = 0;
        it[node * 2 + 1].val = t * (r - mid + 1);
        it[node * 2].q1 = 0;
        it[node * 2].val = t * (mid - l + 1);
        it[node * 2].q2 = t;
        it[node * 2 + 1].q2 = t;
        it[node].q1 = 0;
        it[node].q2 = 0;
    }
    else
    {
        int t = it[node].q1;
        //it[node * 2 + 1].q2 += t;
        it[node * 2 + 1].val += t * (r - mid + 1);
        //it[node * 2].q2 += t;
        it[node * 2].val += t * (mid - l + 1);
        it[node * 2].q1 += t;
        it[node * 2 + 1].q1 += t;
        it[node].q1 = 0;
        it[node].q2 = 0;
    }
}
void update(int node, int l, int r, int u, int v, int val, int cond)
{
    if (r < u || l > v)
        return;
    if (u <= l && r <= v)
    {
        if (cond == 1)
            it[node].q1 += val, it[node].val += val * (r - l + 1);
        else
            it[node].q2 = val, it[node].val = val * (r - l + 1);
        return;
    }

    down(node, l, r);

    int mid = (l + r) / 2;
    update(node * 2, l, mid, u, v, val, cond);
    update(node * 2 + 1, mid + 1, r, u, v, val, cond);
    it[node].val = it[node * 2].val + it[node * 2 + 1].val;
}
ll get(int node, int l, int r, int u, int v)
{
    if (r < u || l > v)
        return 0;
    if (u <= l && r <= v)
    {
        return it[node].val;
    }
    int mid = (l + r) / 2;
    down(node, l, r);
    return get(node * 2, l, mid, u, v) + get(node * 2 + 1, mid + 1, r, u, v);
}
int main()
{
    int k, u, v, cond;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(1, 1, n, i, i, a[i], 1);
    }
    while (m--)
    {
        cin >> k >> u >> v;
        if (k == 3)
            cout << get(1, 1, n, u, v) << endl;
        else
        {
            cin >> cond;
            update(1, 1, n, u, v, cond, k);
        }
    }
}

/*
1: Increase each value in range [a,b] by x.
2: Set each value in range [a,b] to x.
*/