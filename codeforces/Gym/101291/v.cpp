//posman
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
    int n;
    double k, optimize[N], remaining[N], pos, res = 0;
    reset(remaining, 0);
    reset(optimize, 0);
    pp a[N];
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    a[++n] = {0, 0};
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        if (a[i].first == 0)
            pos = i;
    for (int i = pos + 1; i <= n; i++)
    {
        int t = ceil((a[i].second / k));
        optimize[i] = abs(a[i].first) * t;
        remaining[i] = k * t - a[i].second;
        int r = (a[i].second - remaining[i - 1]);
        t = ceil(r / k);
        if (optimize[i] > (i * t + (a[i].first - a[i - 1].first)))
        {
            optimize[i] = abs(a[i].first) * t + a[i].first - a[i - 1].first;
            remaining[i] = k * t - r;
        }
    }
    for (int i = pos - 1; i >= 1; i--)
    {
        int t = ceil(a[i].second / k);
        optimize[i] = abs(a[i].first) * t;
        remaining[i] = k * t - a[i].second;
        int r = (a[i].second - remaining[i + 1]);
        t = ceil(r / k);
        if (optimize[i] > (i * t + (a[i].first - a[i + 1].first)))
        {
            optimize[i] = abs(a[i].first) * t + a[i].first - a[i + 1].first;
            remaining[i] = k * t - r;
        }
    }
    for (int i = 1; i <= n; i++)
        res += optimize[i];
    res = res + abs(a[1].first) + abs(a[n].first);
    cout << res << endl;
}