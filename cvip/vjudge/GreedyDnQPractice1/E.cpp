#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define pp pair<double, double>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;
int n;
double l, w;
pp temp; // first pos, second radius
vector<pp> a;
void solve()
{
    a.clear();
    a.push_back({-999999999, 0});
    for (int i = 1; i <= n; i++)
    {
        cin >> temp.first >> temp.second;
        if (temp.second <= w / 2.0)
            continue;
        double d = sqrt(temp.second * temp.second - (w * w) / 4.0);
        a.push_back({temp.first - d, temp.first + d});
    }

    sort(a.begin(), a.end());
    n = a.size() - 1;
    int i = 0, res = 0, pos = 0;
    while (i < n)
    {
        pos = i;
        for (int j = i + 1; j <= n; j++)
        {
            if (a[j].first > a[i].second)
                break;
            if (a[j].second > a[pos].second)
                pos = j;
        }
        if (i == pos)
            break;
        res++;
        if (a[pos].second >= l)
            break;
        i = pos;
    }
    if (a[pos].second < l)
        res = -1;
    cout << res << endl;
}
int main()
{
    fastio;
    // input_file;
    // output_file;
    int testcase;
    while (cin >> n >> l >> w)
    {
        solve();
    }
}