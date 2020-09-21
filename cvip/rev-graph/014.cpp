//J Jailbreak
#include <bits/stdc++.h>
#define N 101
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
int n, m, dp[N][N], res = 1e9;
bool fee[N][N];
vector<pp> person;
void dfs(int x, int y)
{
    if (x == 5 && y == 9)
        cout << "de";
    if (x == n || x == 1 || y == 1 || y == m)
        return;
    fee[x][y] = false;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
        {
            if (i * j != 0)
                continue;
            if (a[x + i][y + j] != '*' && fee[x + i][y + j] == true)
                dfs(x + i, y + j);
            dp[x][y] = min(dp[x][y], dp[i + x][j + y]);
        }
    if (a[x][y] == '#')
        dp[x][y] += 1;
}
void dfs(int x, int y, int d)
{
    if (a[x][y] == '#')
        d++;
    res = min(res, dp[x][y] + d);
    if (x == n || x == 1 || y == 1 || y == m)
    {
        return;
    }
    fee[x][y] = false;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
        {
            if (i * j != 0)
                continue;
            if (a[x + i][y + j] != '*' && fee[x + i][y + j] == true)
                dfs(x + i, y + j, d);
        }
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            dp[i][j] = 5;
            if (a[i][j] == '$')
                person.push_back({i, j});
            if ((a[i][j] == '.') && (i == 1 || i == n || j == 1 || j == m))
                dp[i][j] = 0;
            if ((a[i][j] == '#') && (i == 1 || i == n || j == 1 || j == m))
                dp[i][j] = 1;
        }

    dfs(person[0].first, person[0].second);
    reset(fee, true);
    dfs(person[1].first, person[1].second, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << res << endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        reset(dp, 0);
        reset(fee, true);
        solve();
    }
}