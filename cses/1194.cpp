#include <bits/stdc++.h>
#define N 1005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(a, val) memset(a, val, sizeof(a));
#define modulo int(1e9 + 7)
#define endl '\n'
using namespace std;
queue<pp> s;
queue<int> val;
int n, m, fee[N][N];
char a[N][N];
pp pre[N][N], path_end, path_start;
bool check(int x, int y)
{
    if (a[x][y] == '#' || a[x][y] == 'M' ||
            fee[x][y] != 0 || x > n || y > m || x < 1 || y < 1)
    {
        return false;
    }
    return true;
}

void bfs()
{
    pp pos;
    int v;
    while (s.empty() != 1)
    {
        v = val.front();
        val.pop();
        pos = s.front();
        s.pop();
        int x = pos.first, y = pos.second;
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
            {
                if (i * j)
                    continue;
                if (check(x + i, y + j))
                {

                    s.push({x + i, y + j});
                    val.push(v);
                    pre[x + i][y + j] = {x, y};
                    fee[x + i][y + j] = v;
                    if ((x + i == 1 || x + i == n || y + j == 1 || y + j == m) && v == 1)
                    {
                        path_end.first = x + i, path_end.second = y + j;
                        return;
                    }
                    //cout << x + i << " " << y + j << v << endl;
                }
            }
    }
}
char convert(int x, int y, int prex, int prey)
{
    if (x == prex - 1)
        return 'D';
    if (x == prex + 1)
        return 'U';
    if (y == prey - 1)
        return 'R';
    return 'L';
}
void print_path()
{
    vector<char> res;
    pp cur;
    if (path_end.first == 0 && path_end.second == 0)
    {
        cout << "NO";
        return;
    }
    while (path_start != path_end)
    {
        cur = pre[path_end.first][path_end.second];
        res.push_back(convert(cur.first, cur.second, path_end.first, path_end.second));
        path_end = cur;
    }
    reverse(res.begin(), res.end());
    cout << "YES \n" << res.size() << endl;
    for (char v : res)
        cout << v;
}
void debug()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%d,%d ", pre[i][j].first, pre[i][j].second);
            //cout << fee[i][j] << " ";
        }
        printf("\n");
        //scout << endl;
    }
}
int main()
{
    reset(pre, -1);
    path_end = {0, 0};
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                path_start = {i, j};
            }
            if (a[i][j] == 'M')
            {
                s.push({i, j});
                val.push(2);
            }
        }
    s.push(path_start);
    val.push(1);
    bfs();
    //debug();
    print_path();
}