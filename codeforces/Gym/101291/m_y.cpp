//zigzag
#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
int main()
{
    int n, a[N], up[N], down[N], type[N], res = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    up[1] = 1, down[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        down[i] = up[i] = 1;
        for (int j = i - 1; j >= 1; j--)
        {
            if (a[i] == a[j])
                continue;
            if (a[i] > a[j])
                up[i] = max(down[j] + 1, up[i]);
            else
                down[i] = max(up[j] + 1, down[i]);
        }
        res = max(res, max(down[i], up[i]));
    }
    // for (int i = 1; i <= n; i++)
    //     cout << up[i] << " ";
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << down[i] << " ";
    cout << res;
}