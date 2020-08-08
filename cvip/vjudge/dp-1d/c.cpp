#include <bits/stdc++.h>
#define maxn 100000
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("out.txt", "w", stdout)
using namespace std;
int n, a[maxn], ss = 0, it[maxn * 4], b[maxn];
map<int, int> compress;
set<int> temp;
void update(int node, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        it[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(node << 1, l, mid, pos, val);
    update(node << 1 | 1, mid + 1, r, pos, val);
    it[node] = max(it[node << 1], it[node << 1 | 1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return -1e9;
    }
    if (u <= l && r <= v)
    {
        return it[id];
    }
    int mid = (l + r) / 2;

    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
void pre_processing()
{
    int x = 0;
    for (auto v : temp)
        compress[v] = ++x;
    for (int i = 1; i <= n; i++)
        a[i] = compress[a[i]];
}
void solve()
{
    memset(it, 0, sizeof(it));
    compress.clear();
    temp.clear();
    int inc = 0, dec = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        temp.insert(a[i]);
    }
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    pre_processing();
    for (int i = 1; i <= n; i++)
    {
        int t = max(get(1, 1, n, 1, a[i] - 1), 0);
        inc = max(inc, t + b[i]);
        //cout << t << " ";
        update(1, 1, n, a[i], t + b[i]);
    }
    memset(it, 0, sizeof(it));
    for (int i = 1; i <= n; i++)
    {
        int t = max(get(1, 1, n, a[i] + 1, n), 0);
        dec = max(dec, t + b[i]);
        //cout << t << " ";
        update(1, 1, n, a[i], t + b[i]);
    }
    //cout << res << endl;
    if (inc >= dec)
        printf("Increasing (%d). Decreasing (%d).\n", inc, dec);
    else
        printf("Decreasing (%d). Increasing (%d).\n", dec, inc);
}
int main()
{
    //freopen("out.txt", "w", stdout);
    int testcase;
    cin >> testcase;
    for (int i = 1; i <= testcase; i++)
    {
        printf("Case %d. ", i);
        solve();
    }
}