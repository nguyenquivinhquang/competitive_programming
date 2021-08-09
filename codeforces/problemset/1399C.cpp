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
    int n, a[N], res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int w = 1; w <= n * 2; w++)
    {
        int p = 0, l = 1, r = n;
        while (l < r)
        {
            int t = a[l] + a[r];
            if (t == w)
            {
                l++, r--, p++;
            }
            else if (t > w)
                r--;
            else
                l++;
        }
        res = max(res, p);
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