#include <bits/stdc++.h>
#define maxn 100001
#define ll double
#define pp pair<ll, ll>
using namespace std;
int it[maxn * 4], a[maxn], pre[maxn * 4], n;

void update(int id, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        it[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid);
    update(id * 2 + 1, mid + 1, r);
    it[id] = max(it[id * 2], it[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return -100000000;
    }
    if (u <= l && r <= v)
    {
        return it[id];
    }
    int mid = (l + r) / 2;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    update(1, 1, n);
    int m = 0, pos = 0, res = 0;
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n+1; i++)
    {
        pre[i] = a[i - 1] + pre[i - 1];
        int temp = get(1, 1, n, pos, i - 1);
        if (temp == -100000000)
            temp = 0;
        res = max(res, pre[i] - m - temp);
        if (pre[i] < m)
        {
            m = pre[i];
            pos = i - 1;
        }
    }
    //res = max(res, pre[n+1] - m - get(1, 1, n, pos, n));

    cout << res;
}