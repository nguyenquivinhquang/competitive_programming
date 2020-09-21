#include <bits/stdc++.h>
#define N 1600
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(a, val) memset(a, val, sizeof(a));
#define modulo int(1e9 + 7)
#define endl '\n'
using namespace std;
double cur_size[N], cut[N], r;
int n = 0;
bool f()
{
    pair<double, int> cur_max = {cur_size[1], 1}, cur_min = {cur_size[1], 1};
    for (int i = 1; i <= n; i++)
    {
        if (cur_max.first < cur_size[i])
            cur_max = {cur_size[i], i};
        if (cur_min.first > cur_size[i])
            cur_min = {cur_size[i], i};
    }
    if (cur_min.first / cur_max.first >= r - 0.0001)
        return true;
    int pos = cur_max.second;
    cur_size[pos] *= (cut[pos] + 1);
    cut[pos]++;
    cur_size[pos] /= (cut[pos] + 1);
    if (f())
        return true;
    else
        return false;
}
void ans()
{
    if (f())
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
            res += cut[i];
        cout << res;
    }
}
int main()
{
    cin >> r >> n;
    for (int i = 1; i <= n; i++)
        cin >> cur_size[i];
    reset(cut, 0);
    sort(cur_size + 1, cur_size + 1 + n);
    ans();
}