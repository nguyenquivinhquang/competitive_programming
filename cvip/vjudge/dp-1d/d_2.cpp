#include <bits/stdc++.h>
#define N 10010
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define qsort(x, size) sort(x + 1, x + 1 + size);
#define reset(x) memset(x, 0, sizeof(x))
using namespace std;
ll find_step(ll x, ll y)
{
    ll step = 0, diff = abs(x - y);
    step = diff / 5, diff %= 5;
    step += diff / 2, diff %= 2;
    step += diff;
    return step;
}

void solve()
{
    ll n, a[N], res = 1e15, m = 100;
    ll value[N], count[N];
    reset(value);
    reset(count);
    map<ll, ll> debt;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    qsort(a, n);
    for (int i = 0; i <= m; i++)
    {
        count[i] = 0;
        value[i] = a[1] - i;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j <= m; j++)
            count[j] += find_step(value[j], a[i]);
    }
    for (int i = 0; i <= m; i++)
        res = min(res, count[i]);
    cout << res << endl;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    // for (int i = 1; i >= -30; i--)
    //     cout << find_step(i, 30) << " ";
}