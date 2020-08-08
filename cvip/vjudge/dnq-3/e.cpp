#include <bits/stdc++.h>
#define ll long long
#define pa pair<int, int>
#define vt vector<int>
#define maxn 1000001
#define reset memset(l, 0, sizeof(l)), l[1] = 1, memset(r, 0, sizeof(r)), r[n] = 1
using namespace std;
vector<pa> a;
vector<int> tree[maxn * 5];
int l[maxn + 1], r[maxn + 1];
int n;
bool cmp1(pa x, pa y)
{
    if (x.first < y.first)
        return true;
    if (x.first > y.first)
        return false;
    if (x.second < y.second)
        return true;
    else
        return false;
}
void merge_tree(vt &x, vt &y, vt &z)
{
    vt L = x, R = y;
    int max_l = L.end() - L.begin(), max_r = R.end() - R.begin(), i = 0, j = 0;
    while (i < max_l && j < max_r)
    {
        if (L[i] <= R[j])
        {
            z.push_back(L[i++]);
        }
        else
        {
            z.push_back(R[j++]);
        }
    }
    while (i < max_l)
        z.push_back(L[i++]);

    while (j < max_r)
        z.push_back(R[j++]);
}
void rs()
{
    for (int i = 1; i <= n; i++)
        l[i] = 1, r[i] = 1;
}
void build_tree(int cur, int left, int right)
{
    if (left == right)
    {
        tree[cur].push_back(l[left]);
        return;
    }
    int mid = (left + right) / 2;
    build_tree(2 * cur + 1, left, mid);
    build_tree(2 * cur + 2, mid + 1, right);
    merge_tree(tree[2 * cur + 1], tree[2 * cur + 2], tree[cur]);
}
int query(int cur, int left, int right, int x, int y, int k)
{

    if (right < x || left > y)
    {
        return 0;
    }
    if (x <= left && right <= y)
    {
        auto t = upper_bound(tree[cur].begin(), tree[cur].end(), k);
        return (upper_bound(tree[cur].begin(), tree[cur].end(), k) - tree[cur].begin());
    }
    int mid = (left + right) / 2;
    return query(2 * cur + 1, left, mid, x, y, k) + query(2 * cur + 2, mid + 1, right, x, y, k);
}
void display()
{
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << l[i] << " ";
}
void pre()
{
    reset;
    rs();
    sort(a.begin(), a.end(), cmp1);
    for (int i = 1; i < n; i++)
    {
        if (a[i].first == a[i - 1].first)
        {
            l[a[i].second] = l[a[i - 1].second] + 1;
        }
        else
        {
            l[a[i].second] = 1;
        }
    }
    //sort(a.begin(), a.end(), cmp2);
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i].first == a[i + 1].first)
        {
            r[a[i].second] = r[a[i + 1].second] + 1;
        }
        else
        {
            r[a[i].second] = 1;
        }
    }
    build_tree(1, 1, n);
}

int main()
{
    //freopen("/media/code/c++/cvip/dnq-3/test.inp", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    int temp;
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back({temp, i + 1});
    }
    pre();
    for (int i = n; i >= 1; i--)
    {
        int b = i - query(1, 1, n, 1, i - 1, r[i]) - 1;
        res += b;
    }
    cout << res;
}