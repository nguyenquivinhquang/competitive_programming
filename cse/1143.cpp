#include <bits/stdc++.h>
#define maxn 200001

using namespace std;
int n, m, guest;
int it[maxn * 4], a[maxn];
void build(int id, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        it[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    it[id] = max(it[id * 2], it[id * 2 + 1]);
}
int get(int id, int l, int r, int val)
{
    if (it[id]<val) return 0;
    if (l == r)
    {
        it[id] -= val;
        return l;
    }

    int mid = (l + r) / 2, x = 0;
    if (it[id * 2] >= val)
        x = get(id * 2, l, mid, val);
    else if (it[id * 2 + 1] >= val)
        x = get(id * 2 + 1, mid + 1, r, val);
    it[id] = max(it[id * 2], it[id * 2 + 1]);
    return x;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        cin >> guest;
        cout << get(1, 1, n, guest)<<" ";
    }
}