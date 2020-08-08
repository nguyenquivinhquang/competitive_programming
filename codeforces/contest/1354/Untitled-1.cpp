#include <bits/stdc++.h>
#define maxn 1000001
//#define maxn 10
#define ii int
using namespace std;
int it[maxn * 4], n, trace[maxn], temp, q;
void build(int node, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        it[node] = trace[l];
        return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    it[node] = it[node * 2] + it[node * 2 + 1];
}
int get_update(ii node, ii l, ii r, ii pos, ii old)
{
    if (l > r)
        return 0;
    if (l == r)
    {
        it[node]--;
        trace[l]--;
        //cout << node << " " << l << endl;
        return 0;
    }
    int mid = (l + r) / 2, x = 0;
    if (it[node * 2] >= pos)
        x = get_update(node * 2, l, mid, pos, old);
    else
        x = get_update(node * 2 + 1, mid + 1, r, pos - it[node * 2], old);
    it[node] = it[node * 2] + it[node * 2 + 1];
    return x;
}
void insert(ii node, ii l, ii r, ii pos, ii old)
{
    if (l > r)
        return;
    if (l == r)
    {
        it[node]++;
        trace[old]++;
        //cout << node << " " << l << endl;
        return;
    }
    int mid = (l + r) / 2, x = 0;
    if (pos<=mid)
        insert(node * 2, l, mid, pos, old);
    else
        insert(node * 2 + 1, mid + 1, r, pos, old);
    it[node] = it[node * 2] + it[node * 2 + 1];
    return;
}
int main()
{
    //freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    memset(trace, 0, sizeof(trace));
    memset(it, 0, sizeof(it));
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        trace[temp]++;
    }

    build(1, 1, maxn - 1);
    for (int i = 1; i <= q; i++)
    {
        cin >> temp;
        if (temp < 0)
        {
            temp = -temp;
            get_update(1, 1, maxn - 1, temp, temp);
        }
        else
        {
            insert(1, 1, maxn - 1, temp, temp);
        }
    }
    for (int i = 1; i < maxn; i++)
        if (trace[i] > 0)
        {
            cout << i << " ";
            return 0;
        }
    cout << 0;
}
