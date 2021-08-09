#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
void solve()
{
    ll pre[N], res = 0;
    int n, a[N];
    reset(pre);
    map<int, int> trace;
    string x;
    cin >> n;
    cin >> x;

    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + int(x[i - 1]) - '0';
        if (pre[i] - pre[i - 1] == 1)
            res += 1;
        int t = pre[i] - i;
        res += trace[t];
        trace[pre[i - 1] - i + 1]++;
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