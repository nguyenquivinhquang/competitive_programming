#include <bits/stdc++.h>
#define maxn 300001
#define ii int
using namespace std;
int it[maxn * 4], n, a[maxn], temp;
void build(int node, int l, int r)
{
    if (l == r)
    {
        it[node] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    it[node] = it[node * 2] + it[node * 2 + 1];
}
int get_update(ii node, ii l, ii r, ii pos)
{
    if (l == r)
    {
        it[node] = 0;
        return a[l];
    }
    int mid = (l + r) / 2, x = 0;
    if (it[node * 2] >= pos)
        x = get_update(node * 2, l, mid, pos);
    else
        x = get_update(node * 2 + 1, mid + 1, r, pos - it[node * 2]);
    it[node] = it[node * 2] + it[node * 2 + 1];
    return x;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        cout << get_update(1, 1, n, temp) << " ";
    }
}