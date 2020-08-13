#include <bits/stdc++.h>
#define maxn 100
#define ll long long
using namespace std;
struct dk
{
    ll l, r, val;
};
dk it[maxn];
int q, n, a[maxn];
void build(int node, int l, int r)
{
    if (l == r)
    {
        it[node].val = a[l];
        l = 1, r = 1;
        return;
    }
    if (l > r)
        return;
    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
}
void down(int node)
{
    it[node*2].l;
}
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}
