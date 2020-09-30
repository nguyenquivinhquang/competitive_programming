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
ll n, q, a[N];

void solve()
{
    ll res = -1;
    set<ll, greater<ll>> down;
    set<ll, greater<ll>> up;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    res = a[1];
    up.insert(a[1]), down.insert(-1e9);
    for (int i = 2; i <= n; i++)
    {
        res = max(res, a[i]);
        ll u = max(a[i], a[i] + *down.begin());
        ll d = *up.begin() - a[i];
        up.insert(u), down.insert(d);
        res = max(max(res, u), d);
    }
    cout << res << endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}