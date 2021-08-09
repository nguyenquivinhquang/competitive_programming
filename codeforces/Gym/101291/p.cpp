//Cameras
#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
ll n, m, a[N], pre[N];
int main()
{
    ll temp, k;
    cin >> n >> k >> m;
    for (int i = 1; i <= k; i++)
    {
        cin >> temp;
        a[temp] = 1;
    }
    for (int i = 1; i < m; i++)
        pre[i] = pre[i - 1] + a[i];
    if (pre[m - 1] < 1)
    {
        a[m - 1] = 1;
        pre[m - 1]++;
    }
    for (int i = m; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
        if (pre[i] - pre[i - m] <= 1)
        {
            a[i] = 1;
            pre[i] = pre[i - 1] + 1;
        }
    }
    cout << pre[n] - k << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << i << " ";
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << a[i] << " ";
}