#include <bits/stdc++.h>
#define maxn 200001
using namespace std;
struct Gb
{
    int l, r, id;
};

int n, m, lim = 0, it[maxn * 4], trace[maxn], res[maxn];
vector<int> a, temp;
vector<Gb> queries;

int encode(int x)
{
    return lower_bound(temp.begin(), temp.end(), x) - temp.begin() + 1;
}
bool cmp(Gb x, Gb y)
{
    if (x.r != y.r)
        return (x.r < y.r);
    if (x.l != y.l)
        return (x.l < y.l);
    return x.id < y.id;
}
void compressed()
{
    sort(temp.begin(), temp.end());
    temp.resize(distance(temp.begin(), unique(temp.begin(), temp.end())));
    for (auto &c : a)
        c = encode(c), lim = max(lim, c);
}
void update(int node, int l, int r, int pos, bool dk) // dk true: insert, false:erase
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        it[node] = dk;
        return;
    }
    int mid = (l + r) / 2;
    update(node * 2, l, mid, pos, dk);
    update(node * 2 + 1, mid + 1, r, pos, dk);
    it[node] = it[node * 2] + it[node * 2 + 1];
}
int get(int node, int l, int r, int pos)
{
    if (pos <= l)
        return it[node];
    if (pos > r)
        return 0;
    if (l == r)
        return it[node];
    int mid = (l + r) / 2;
    return get(node * 2, l, mid, pos) + get(node * 2 + 1, mid + 1, r, pos);
}
void preprocessing()
{
    memset(trace, 0, sizeof(trace));
    memset(it, 0, sizeof(it));
    sort(queries.begin(), queries.end(), cmp);
    compressed();
}
int main()
{
    int l, r;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> l;
        a.push_back(l);
        temp.push_back(l);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> l >> r;
        queries.push_back({l, r, i});
    }
    preprocessing();
    int pos_q = 0;
    for (int i = 0; i < n; i++)
    {
        update(1, 1, maxn, trace[a[i]], 0);
        trace[a[i]] = i + 1;
        update(1, 1, maxn, i + 1, 1);
        if (queries[pos_q].r == i + 1)
        {
            res[queries[pos_q].id] = get(1, 1, maxn, queries[pos_q].l);
            while (queries[pos_q].r == queries[pos_q + 1].r)
            {
                pos_q++;
                res[queries[pos_q].id] = get(1, 1, maxn, queries[pos_q].l);
            }
            pos_q++;
        }
    }
    for (int i = 1; i <= m; i++)
        cout << res[i] << '\n';
}