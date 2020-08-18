#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x,val) memset(x, val, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
int n, level[N], lgn, dp[N][int(log2(N + 10))];
vector<int> vertices[N];

void dfs(int u, int preu)
{
    level[u] = level[preu] + 1;
    dp[u][0] = preu;
    for (int i = 1; i <= lgn; i++)
        dp[u][i] = dp[dp[u][i - 1]][i - 1];
    for (int v : vertices[u])
    {
        if (preu == v)
            continue;
        dfs(v, u);
    }
}

int main()
{
    reset(level, -1);
    int x, y, q;

    cin >> n >> q;
    lgn = ceil(log2(n));
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        y = i;
        vertices[x].push_back(y), vertices[y].push_back(x);
    }
    dfs(1, 0);
    while (q--)
    {
        cin >> x >> y;
        int i = 0;
        while (y > 0)
        {
            if ( y & i )
                x = dp[x][i];
            y >>= 1, i++;
        }
        cout << y << endl;
    }
    for (int i=0; i<lgn; i++)
        cout << dp[4][i];
}