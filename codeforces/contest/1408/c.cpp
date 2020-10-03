#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;
double t1[N], t2[N], a[N];
void solve()
{
    int n, l;
    double ans;
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    t1[0] = t2[n + 1] = a[0] = 0;
    a[n + 1] = l;

    for (int i = 1; i <= n + 1; i++)
        t1[i] = t1[i - 1] + double(a[i] - a[i - 1]) / double(i);

    for (int i = n; i >= 0; i--)
        t2[i] = t2[i + 1] + double(a[i + 1] - a[i]) / double(n - i + 1);

    for (int i = 1; i <= n + 1; i++)
    {
        if (t1[i] == t2[i])
        {
            ans = t1[i];
            break;
        }
        if (t1[i] > t2[i])
        {
            ans = t2[i];
            double s = (a[i] - a[i - 1]) - ((t2[i] - t1[i - 1]) * i);
            ans += s / (n + 2);
            break;
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
}
int main()
{
    fastio;
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}