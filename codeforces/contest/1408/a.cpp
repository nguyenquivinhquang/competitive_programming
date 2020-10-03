#include <bits/stdc++.h>
#define N 500
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
void solve()
{
    int n, a[N], b[N], c[N];
    vector<int> res;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    res.push_back(a[1]);
    for (int i = 2; i < n; i++)
    {
        if (a[i] != res.back())
            res.push_back(a[i]);
        else if (b[i] != res.back())
            res.push_back(b[i]);
        else
            res.push_back(c[i]);
    }
    if (a[n] != a[1] && a[n] != res.back())
        res.push_back(a[n]);
    else if (b[n] != a[1] && b[n] != res.back())
        res.push_back(b[n]);
    else
        res.push_back(c[n]);
    for (auto v : res)
        cout << v << " ";
    cout << endl;
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