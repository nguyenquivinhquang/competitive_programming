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

    ll l, r, m, dif;
    cin >> l >> r >> m;

    dif = abs(l - r);

    for (int i = l; i <= r + 1; i++)
    {
        if (m % i <= dif && i <= m)
        {
            cout << i << ' ' << l + m % i << ' ' << l << endl;
            return;
        }
        if (i - m % i <= dif)
        {
            cout << i << ' ' << l << ' ' << l + (i - m % i) << endl;
            return;
        }
    }
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