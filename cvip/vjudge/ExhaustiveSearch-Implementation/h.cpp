#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
#define N 20
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
bitset<120> trace;
set<string> res;
void dfs(int u, int v, int d)
{
    fee[u][v] = false;
    if (u < 1 || v < 1 || u > n || v > n)
        return;
    if (d == 8)
    {
        //res.insert(trace.to_ulong());
        res.insert(trace.to_string());
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
                int val = (u + x) * (n + 1) + (v + y);
                trace[val] = 1;
                dfs(u + x, v + y, d + 1);
                trace[val] = 0;
            }
        }
    fee[u][v] = true;
}
void solve()
{
    reset(fee, true);
    trace.set(0);
    res.clear();
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 'X')
            {
                int val = (n + 1) * (i) + (j);
                trace[val] = 1;
                dfs(i, j, 1);
                trace[val] = 0;
            }

    cout << res.size() << endl;
}
int main()
{
    fastio;
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}