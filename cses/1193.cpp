#include <bits/stdc++.h>
#define N 1005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(a, val) memset(a, val, sizeof(a));
#define modulo int(1e9 + 7)
#define endl '\n'
using namespace std;
bool fee[N][N];
char a[N][N];
int n, m;
pp ss, ee;
vector<char> trace, res;
void check()
{
    if (trace.size() < res.size() || res.empty())
        res = trace;
}

void dfs(int x, int y)
{
    if (fee[x][y] == false || a[x][y] == '#' || x > n || y > m || x < 1 || y < 1)
    {
        if (trace.size())
            trace.pop_back();
        return;
    }
    if (a[x][y] == 'B')
    {
        check();
        if (trace.size())
            trace.pop_back();
        return;
    }
    fee[x][y] = false;
    trace.push_back('D');
    dfs(x + 1, y);
    trace.push_back('U');
    dfs(x - 1, y);
    trace.push_back('R');
    dfs(x, y + 1);
    trace.push_back('L');
    dfs(x, y - 1);
    fee[x][y] = true;
    trace.pop_back();
}
int main()
{
    cin >> n >> m;
    reset(fee, true);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
                ss = {i, j};
        }
    dfs(ss.first, ss.second);
    if (res.size() != 0)
    {
        cout << "YES \n";
        cout << res.size() << endl;
        for (char i : res)
            cout << i;
    }
    else
        cout << "NO";
}