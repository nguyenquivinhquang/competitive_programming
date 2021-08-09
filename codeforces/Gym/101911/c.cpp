#include <bits/stdc++.h>
#define N 200005
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
ll a[N], n;
int solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll t = a[1];
    multiset<ll> q;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % t != 0)
            return -1;
        a[i] /= t;
        q.insert(a[i]);
    }
    ll res = 0;

    while (q.size() > 1)
    {
        double x, y, t;
        x = *q.begin(), q.erase(q.begin());
        y = *q.begin(), q.erase(q.begin());

        ll k = log2(y / x);
        if (pow(2, k) != y / x)
            return -1;
        q.insert(y * 2);
        res += k;
    }
    return res;
}
int main()
{
    cout << solve();
}
