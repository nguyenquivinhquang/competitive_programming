#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
void solve()
{
    int x0, x1, x2, y0, y1, y2, m;
    ll sum = 0;
    cin >> x0 >> x1 >> x2 >> y0 >> y1 >> y2;
    m = min(x0, y2);
    x0 -= m, y2 -= m;
    m = min(y2, x2);
    y2 -= m, x2 -= m;
    m = min(y2, x1);
    y2 -= m, x1 -= m;
    sum += -2 * m;
    m = min(x2, y1);
    sum += m * 2;
    x2 -= m, y1 -= m;
    cout << sum << endl;
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