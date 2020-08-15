#include <bits/stdc++.h>
#define N 300
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
void solve()
{
    int n, p[N];
    string a;
    p[0] = 0;
    cin >> a;
    n = a.length();
    a = "c" + a;
    for (int i = 1; i <= n; i++)
    {

        if (a[i] == '1')
            p[i] = p[i - 1] + 1, p[i - 1] = 0;
        else
            p[i] = 0;
    }
    ll res = 0;
    sort(p + 1, p + 1 + n);
    for (int i = n; i >= 1; i -= 2)
        res += p[i];
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