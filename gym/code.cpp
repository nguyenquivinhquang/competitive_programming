#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll fac(ll n, ll k)
{
    if (k > n) return 0;
    double res = 1.0, j = 1.0;
    for (int i = n - k + 1; i <= n; i++)
    {
        res = res * i;
        if (j <= k)
            res /= j, j + +;
    }
for (int i = j; i <= k; i++)
    res /= i;
return res;
}
ll countSquares(ll m, ll n)
{
if (n < m)
        swap(m, n);

    return m * (m + 1) * (2 * m + 1) /
           6 + (n - m) * m * (m + 1) / 2;
}
ll count_dc(ll n, ll m) // dem dg cheo
{
    int trace[n + 1][m + 1];
    memset(trace, 0, sizeof(trace));
    ll res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            trace[i][j] = fac(min(i, j), 3);
            res += trace[i][j] - trace[i - 1][j - 1];
        }
    return res * 2;
}
int main()
{
    cout << fac(52, 6);
    //freopen("input.txt","r",stdin);
    //freopen("quang_out.txt","w", stdout);

    int testcase;
    ll n, m;
    cin >> testcase;
    while (testcase--)
    {
        cin >> n >> m;
        cout << fac(n * m, 3) - count_dc(n, m) - fac(n, 3)*m - fac(m, 3)*n << endl;
    }

}