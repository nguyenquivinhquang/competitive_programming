#include <bits/stdc++.h>
#define ll long long
#define vt vector<int>
#define maxn 50002
#define maxk 513
#define reset memset(dp, 0, sizeof(dp)), memset(fee, 1, sizeof(fee))
using namespace std;
vt a[maxn];
int dp[maxn][maxk], n, k, res = 0;
bool fee[maxn];
void compute(int u, int v)
{
    for (int i = 0; i < k; i++)
        res += dp[u][i] * dp[v][k - i - 1];
    for (int i = 0; i < k; i++)
    {
        dp[u][i + 1] += dp[v][i];
    }
    
}
void dfs(int u)
{
    dp[u][0]++;
    fee[u] = false;
    for (auto v : a[u])
        if (fee[v] == true)
        {
            dfs(v);
            //dp[u][1]++;
            compute(u, v);
        }
}
void debug()
{
    for (int u = 1; u <= n; u++)
    {
        cout << "dinh " << u << endl;
        for (int v = 1; v <= 3; v++)
        {
            cout << "canh " << v << " " << dp[u][v] << endl;
        }
    }
}
int main()
{
    //freopen("output.out", "w", stdout);
    int x, y;
    reset;
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1);
    //debug();
    cout << res;
}
/*
5 2
1 2
2 3
3 4
2 5
*/