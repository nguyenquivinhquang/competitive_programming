#include <bits/stdc++.h>
#define ll long long
#define maxn 50001
#define lim -1000000000000000
using namespace std;

struct quangcute
{
    ll pre, surf, max, sum;
};
ll a[maxn];
int n;
quangcute tree[maxn * 4], res[maxn * 4];
void build_tree(int nod, int l, int r)
{
    if (l == r)
    {
        tree[nod].max = a[l], tree[nod].sum = a[l], tree[nod].pre = a[l], tree[nod].surf = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build_tree(nod * 2, l, mid), build_tree(nod * 2 + 1, mid + 1, r); // build tree
    tree[nod].sum = tree[nod * 2].sum + tree[nod * 2 + 1].sum;
    tree[nod].pre = max(tree[nod * 2].pre, tree[nod * 2].sum + tree[nod * 2 + 1].pre);        // compute pre nod
    tree[nod].surf = max(tree[nod * 2 + 1].surf, tree[nod * 2 + 1].sum + tree[nod * 2].surf); //compute surf nod
    tree[nod].max = max(max(tree[nod * 2].max, tree[nod * 2 + 1].max), tree[nod * 2].surf + tree[nod * 2 + 1].pre);
    tree[nod].max = max(tree[nod].max, tree[nod].sum);
    //cout << "nod: " << nod << ", l: " << l << " va r: " << r << " gt: " << tree[nod].max << endl;
    return;
}
void reset(int nod)
{
    res[nod].max = lim;
    res[nod].pre = lim;
    res[nod].sum = lim;
    res[nod].surf = lim;
}
void query(int nod, int l, int r, int x, int y)
{
    reset(nod);
    if (r < x || l > y)
        return;
    if (l >= x && y >= r || l == r)
    {
        res[nod] = tree[nod];
        return;
    }
    int mid = (l + r) / 2;
    query(nod * 2, l, mid, x, y), query(nod * 2 + 1, mid + 1, r, x, y);
    res[nod].sum = res[nod * 2].sum + res[nod * 2 + 1].sum;
    res[nod].pre = max(res[nod * 2].pre, res[nod * 2].sum + res[nod * 2 + 1].pre);        // compute pre nod
    res[nod].surf = max(res[nod * 2 + 1].surf, res[nod * 2 + 1].sum + res[nod * 2].surf); //compute surf nod
    res[nod].max = max(max(res[nod * 2].max, res[nod * 2 + 1].max), res[nod * 2].surf + res[nod * 2 + 1].pre);
    res[nod].max = max(res[nod].max, res[nod].sum);
}
int main()
{
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(tree, 0, sizeof(tree));
    build_tree(1, 1, n);
    int q, l, r;
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        //memset(res, 0, sizeof(res));
        query(1, 1, n, l, r);
        cout << res[1].max << endl;
    }
}
/*
10
20 20 -90 10 20 20 20 -50 30 35
3
1 10
4 9
2 7
*/