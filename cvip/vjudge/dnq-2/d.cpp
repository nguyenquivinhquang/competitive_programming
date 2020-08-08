#include <bits/stdc++.h>
#define maxn 100010
#define vt vector<int>
using namespace std;

int n, m;
vector<int> tree[maxn * 4];
int a[maxn * 5], b[maxn * 4];
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

void build_tree(int cur, int l, int r)
{
    if (l == r)
    {
        tree[cur].push_back(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build_tree(2 * cur + 1, l, mid);                             // Build left tree
    build_tree(2 * cur + 2, mid + 1, r);                         // Build right tree
    merge_tree(tree[2 * cur + 1], tree[2 * cur + 2], tree[cur]); //Merging the two sorted arrays
    //tree[cur].push_back(1000000000);
}
int query(int cur, int l, int r, int x, int y, int k)
{

    if (r < x || l > y)
    {
        return 0;
    }
    if (x <= l && r <= y)
    {
        return lower_bound(tree[cur].begin(), tree[cur].end(), k) - tree[cur].begin();
    }
    int mid = (l + r) / 2;
    return query(2 * cur + 1, l, mid, x, y, k) + query(2 * cur + 2, mid + 1, r, x, y, k);
}
int Gb(int i, int j, int k)
{
    int l = 1, r = n, mid;
    int count = 0;
    int x = (j - i) + 1;
    int ans;
    while (l <= r)
    {
        mid = (l + r) / 2;
        count = query(1, 1, n, i, j, b[mid]);
        if (count <= k)
        {
            l = mid + 1;
            ans = b[mid];
        }
        else
            r = mid - 1;
    }
    return ans;
}
void debug()
{
    vt x = {1, 8, 9, 14}, y = {2, 4, 12}, z;
    merge_tree(x, y, z);
}
int main()
{
    //freopen("/media/code/c++/cvip/dnq-2/input.txt", "r", stdin);
    //freopen("/media/code/c++/cvip/dnq-2/output.txt", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    build_tree(1, 1, n);
    int x, y, k;
    for (int i = 1; i <= m; i++)
    {

        cin >> x >> y >> k;
        cout << Gb(x, y, k) << '\n';
    }
}