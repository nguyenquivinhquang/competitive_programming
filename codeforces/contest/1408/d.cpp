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
pp light[N], rob[N];
int n, m;
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> rob[i].first >> rob[i].second;
    for (int i = 1; i <= m; i++)
        cin >> light[i].first >> light[i].second;

    int debtX = 0, debtY = 0, res = 0;

    for (int i = 1; i <= n; i++)
    {
        rob[i].first += debtX, rob[i].second += debtY;
        int maxX = -1, maxY = -1;
        for (int j = 1; j <= m; j++)
            if (light[j].first >= rob[i].first && light[j].second >= rob[j].second)
            {
                if (light[j].first - rob[i].first < light[j].second - rob[i].second)
                {
                    debtX = light[j].first - rob[i].first + 1;
                    res += light[j].first - rob[i].first + 1;
                    rob[i].first += light[j].first - rob[i].first + 1;
                }
                else
                {
                    debtY = light[j].second - rob[i].second + 1;
                    res += light[j].second - rob[i].second + 1;
                    rob[i].second = light[j].second - rob[i].second + 1;
                }
            }
    }
    cout << res << endl;
}
int main()
{
    fastio;
    // int testcase;
    // cin >> testcase;
    // while (testcase--)
    // {
    //     solve();
    // }
    solve();
}