#pragma GCC optimize("O3")
#pragma GCC optimization("unroll-loops")
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
bool cmpx(pp x, pp y)
{
    if (x.first != y.first)
        return x.first < y.first;
    return x.second < y.second;
}
bool cmpy(pp x, pp y)
{
    if (x.second != y.second)
        return x.second < y.second;
    else
        return x.first < y.first;
}
int n;
pp a[N], res1, res2, t[N];

double distance(pp &x, pp &y)
{
    return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}
double update(pp &x, pp &y, double &dis)
{
    double d = distance(x, y);
    if (d < dis)
    {
        res1 = x, res2 = y;
        dis = d;
        return d;
    }
    else
        return dis;
}
double vet(int l, int r)
{
    double d = 1e12;
    for (int i = l; i <= r; i++)
        for (int j = i + 1; j <= r; j++)
            d = min(d, update(a[i], a[j], d));
    return d;
}
double closetPoints(int l, int r)
{
    if (r - l + 1 < 3)
        return vet(l, r);
    int mid = (l + r) >> 1;
    double d1 = closetPoints(l, mid);
    double d2 = closetPoints(mid + 1, r);
    double d = min(d1, d2);

    int size = 0;
    for (int i = mid; i >= 1; i--)
    {
        if (abs(a[i].first - a[mid].first) > d)
            continue;
        t[size++] = a[i];
    }

    for (int i = mid + 1; i <= n; i++)
    {
        if (abs(a[i].first - a[mid].first) > d)
            continue;
        t[size++] = a[i];
    }

    sort(t, t + size, cmpy);
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            update(t[i], t[j], d);
            if (abs(t[i].second - t[j].second) > d) break;
        }
    }
    sort(a + l, a + r + 1, cmpy);
    return d;
}
void solve()
{
}
int main()
{
    fastio;
    int testcase;
    while (cin >> n)
    {
        if (n == 0)
            break;
        for (int i = 1; i <= n; i++)
            cin >> a[i].first >> a[i].second;
        sort(a + 1, a + 1 + n, cmpx);
        closetPoints(1, n);
        cout << fixed << setprecision(2);
        cout << res1.first << " " << res1.second << " " << res2.first << " " << res2.second << endl;
    }
}