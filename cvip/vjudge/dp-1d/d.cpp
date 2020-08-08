#include <bits/stdc++.h>
#define N 10001
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
using namespace std;
int find_step(int x, int y)
{
    int step = 0, diff = abs(x - y);
    step = diff / 5, diff %= 5;
    step += diff / 2, diff %= 2;
    step += diff;
    return step;
}
void solve()
{
    int n, a[N], step = 0, debt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    // for (int i = 1; i < n; i++)
    // {
    //     a[i] += debt;
    //     step += find_step(a[i], a[i + 1] + debt);
    //     debt += a[i + 1] - a[i];
    //     a[i + 1] = (-debt + a[i + 1]);
    // }
    // cout << step << endl;
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
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