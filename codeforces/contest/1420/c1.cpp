#include <bits/stdc++.h>
#define N 300005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("r", "input.txt", stdin);
#define output_file freopen("w", "output.txt", stdout);
using namespace std;
int a[N], n;
ll check(int i)
{
    ll res = 0;
    if (a[i - 1] < a[i] && a[i] > a[i + 1])
        res += a[i];
    if (a[i - 1] > a[i] && a[i] < a[i + 1])
        res -= a[i];
    return res;
}
ll check2(int i)
{
    ll res = 0;
    if (a[i - 1] < a[i] && a[i] > a[i + 1])
        res -= a[i];
    if (a[i - 1] > a[i] && a[i] < a[i + 1])
        res += a[i];
    return res;
}
void solve()
{
    ll q, res = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = a[n + 1] = 0;
    for (int i = 1; i <= n; i++)
    {
        res += check(i);
    }
    cout << res << endl;
    int l, r;
    while (q--)
    {
        cin >> l >> r;
        set<int> query;
        query.insert(l), query.insert(l - 1), query.insert(l + 1), query.insert(r - 1), query.insert(r + 1), query.insert(r);
        for (auto i : query)
            res += check2(i);
        swap(a[l], a[r]);
        for (auto i : query)
            res += check(i);
        cout << res << endl;
    }
}
int main()
{
    fastio;
    int testcase;
    cin >> testcase;
    while (testcase--)
        solve();
}