#include <bits/stdc++.h>
#define maxn 1001
using namespace std;
int n, q, tree[maxn][maxn], res = 0;
bool forest[maxn][maxn];
void debug()
{
    cout << "debug" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << tree[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    memset(tree, sizeof(tree), 0);
    cin >> n >> q;
    char temp;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> temp;
            if (temp == '*')
                forest[i][j] = 1;
            else
                forest[i][j] = 0;
            tree[i][j] = tree[i - 1][j] + tree[i][j - 1] - tree[i - 1][j - 1] + forest[i][j];
        }
    //debug();

    int x, y, u, v;
    while (q--)
    {
        cin >> u >> v >> x >> y;
        cout << tree[x][y] - tree[u-1][y] - tree[x][v-1] + tree[u - 1][v - 1] << endl;
    }
}