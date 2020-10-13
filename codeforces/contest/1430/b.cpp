#include <bits/stdc++.h>
#define N 200005
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
ll a[N], n, k;
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int b = 1;

    for (int i = n - 1; i >= 1; i--)
    {
        if (i == n || k == 0)
            break;
        a[n] += a[i];
        a[i] = 0;
        k--;
    }
    cout << a[n] << endl;
}
int main()
{
    //fastio;
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}