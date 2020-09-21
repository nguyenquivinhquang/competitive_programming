#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
void solve()
{

    ll n, a[N], m = -1e19;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll cur = 1, x = 1;
    a[n + 1] = 1;
    for (int i = 0; i <= 5; i++)
    {
        x *= a[n - i + 1];
        ll y = 1;
        for (int j = 1; j <= 5 - i; j++)
            y *= a[j];
        m = max(m, x * y);
    }
    cout << m << endl;
    
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