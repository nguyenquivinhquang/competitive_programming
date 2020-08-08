#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
void solve()
{
    ll step = 0;
    ll n, a[N], b[N], b_min, a_min;
    a_min = b_min = 1e10;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a_min = min(a_min, a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        b_min = min(b_min, b[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        ll t = min(a[i] - a_min, b[i] - b_min);
        step += t;
        a[i] -= t, b[i] -= t;
        step += a[i] - a_min + b[i] - b_min;
    }
    cout << step << endl;
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