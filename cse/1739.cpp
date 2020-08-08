#include <bits/stdc++.h>
#define maxn 1001
using namespace std;
int n, q, tree[maxn][maxn], res = 0;
bool forest[maxn][maxn];
void add(int x, int y, int delta)
{
    for (int i = x; i <= n; i = i | (i + 1))
        for (int j = y; j <= n; j = j | (j + 1))
            tree[i][j] += delta;
}
int sum(int x, int y)
{
    int ret = 0;
    for (int i = x; i > 0; i = (i & (i + 1)) - 1)
        for (int j = y; j > 0; j = (j & (j + 1)) - 1)
            ret += tree[i][j];
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //memset(tree, sizeof(tree), 0);
    cin >> n >> q;
    char temp;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> temp;
            if (temp == '*')
            {
                add(i, j, 1);
                forest[i][j] = 1;
            }
            else
                forest[i][j] = 0;
        }

    int x, y, u, v, k;
    while (q--)
    {
        cin >> k;
        if (k == 1)
        {
            cin >> x >> y;
            if (forest[x][y] == 1)
            {
                forest[x][y] = 0;
                add(x, y, -1);
            }
            else
            {
                forest[x][y] = 1;
                add(x, y, 1);
            }
        }
        else
        {
            cin >> u >> v >> x >> y;
            cout << sum(x, y) - sum(u - 1, y) - sum(x, v - 1) + sum(u - 1, v - 1) << '\n';
        }
    }
}