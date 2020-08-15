#include <bits/stdc++.h>
#define N 250
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
void solve()
{
    vector<ll> x, y, z;
    ll r, g, b, temp;
    x.push_back(0), y.push_back(0), z.push_back(0);
    cin >> r >> g >> b;
    for (int i = 1; i <= r; i++)
    {
        cin >> temp;
        x.push_back(temp);
    }
    for (int i = 1; i <= g; i++)
    {
        cin >> temp;
        y.push_back(temp);
    }
    for (int i = 1; i <= b; i++)
    {
        cin >> temp;
        z.push_back(temp);
    }
    ll res = 0;
    sort(x.begin(), x.end()), sort(y.begin(), y.end()), sort(z.begin(), z.end());
    while (1 != 0)
    {
        if (x[r] * y[g] >= x[r] * z[b] && x[r] * y[g] >= y[g] * z[b] && r * g > 0)
        {
            res += x[r--] * y[g--];
        }
        else if (x[r] * z[b] >= x[r] * y[g] && x[r] * z[b] >= y[g] * z[b] && r * b > 0)
        {
            res += x[r--] * z[b--];
        }
        else
        {
            res += y[g--] * z[b--];
        }
        //cout << r << " " << g << " " << b << endl;
        if ((r == 0 && b == 0) || (r == 0 && g == 0) || (g == 0 && b == 0))
            break;
    }
    cout << res << endl;
}
int main()
{
    // freopen("/mnt/CODE/competitive_programming/codeforces/problemset/out.txt", "r", stdin);
    // freopen("out1.txt", "w", stdout);
    fastio;
    //solve();
    cout << (9&&0);
}