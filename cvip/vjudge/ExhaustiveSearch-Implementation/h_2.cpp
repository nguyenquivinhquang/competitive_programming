#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("r", "input.txt", stdin);
#define output_file freopen("w", "output.txt", stdout);
using namespace std;
char a[N][N];
bool fee[N][N];
int n;
vector<pp> trace;
set<string> res;
void dfs(int u, int v, int d)
{
    fee[u][v] = false;
    if (u < 1 || v < 1 || u > n || v > n)
        return;
    if (d == 8)
    {
        vector<pp> temp = trace;
        sort(temp.begin(), temp.end());
        string x = "";
        for (auto v : temp)
        {
            x = x + char(v.first) + char(v.second) + ',';
        }
        res.insert(x);
        fee[u][v] = true;
        return;
    }
    for (int x = -1; x <= 1; x++)
        for (int y = -1; y <= 1; y++)
        {
            if (x * y != 0)
                continue;
            if (fee[u + x][v + y] == true && a[u + x][v + y] == 'X')
            {
                trace.push_back({u + x, v + y});
                dfs(u + x, v + y, d + 1);
                trace.pop_back();
            }
        }
    fee[u][v] = true;
}
void solve()
{

    cin >> n;
    res.clear();
    trace.clear();
    for (int i = 1; i <= n; i++)

        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            fee[i][j] = true;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 'X')
            {
                trace.push_back({i, j});
                dfs(i, j, 1);
                trace.pop_back();
            }
    cout << res.size() << endl;
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