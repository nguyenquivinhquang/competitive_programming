#include <bits/stdc++.h>
#define maxn 100
using namespace std;
int n, m;
vector<int> bus[maxn], train[maxn];
bool fee[maxn][maxn];
void create_road()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (fee[i][j] = 0)
            {
                bus[i].push_back(j);
                bus[j].push_back(i);
            }
}
int main()
{
    int u, v;
    memset(fee, false, sizeof(fee));
    cin >>
        n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        train[u].push_back(v);
        train[v].push_back(u);
        fee[u][v] = 1, fee[v][u] = 1;
    }
}