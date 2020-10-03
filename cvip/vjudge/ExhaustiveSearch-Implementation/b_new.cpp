#include <bits/stdc++.h>
#define N 100
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
int n, m;
pp a[N], fi, la;
bool check(int ss, vector<int> &b)
{
    map<int, int> trace;
    trace[fi.second]++, trace[la.first]++;
    for (int i : b)
        trace[a[i].first]++, trace[a[i].second]++;
    for (auto v : trace)
        if (v.second % 2 != 0)
            return false;
    return true;
}
bool solve()
{
    ll limit = 1;

    cin >> m;
    cin >> fi.first >> fi.second;
    cin >> la.first >> la.second;
    for (int i = 1; i <= m; i++)
        cin >> a[i].first >> a[i].second;

    for (int i = 1; i <= m; i++)
        limit *= 2;

    for (int i = 0; i < limit; i++)
    {
        vector<int> vertice;
        for (int j = 0; j < m; j++)
            if (i & (1 << j))
                vertice.push_back(j + 1);
        if (vertice.size() == n)
        {
            if (check(fi.second, vertice))
                return true;
        }
    }
    return false;
}
int main()
{
    fastio;
    while (1 != 0)
    {
        cin >> n;
        if (n == 0)
            break;
        if (solve())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    cond
}