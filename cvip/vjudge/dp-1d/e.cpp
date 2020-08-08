#include <bits/stdc++.h>
#define N 1000
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;

void solve()
{
    int n, m, cut = 1, res = 1e9;
    double t, a[N + 5];
    cin >> t >> n;
    t += 0.0001;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    quyen_sort(a, n);
    int x, y;
    for (int j = 1; j <= n; j++)
    {
        cut = 1;
        y = (a[j] / (1 + t)), x = a[j] - y;
        //cout << x << " " << y;
        for (int i = 1; i <= n; i++)
            if (i != j) 
            {
                int r = ceilf(a[i] / x), l = int(a[i] / y);
                //m = min(ceilf(a[i] / x), ceilf(a[i] / y)) - 1;
                cout << l << " " << r << endl;
                m = m < 0 ? 1e9 : m;
                cut += m;
            }

        res = min(cut, res);
    }
    cout << res;
}
int main()
{
    solve();
}