#include <bits/stdc++.h>
#define N 200001
using namespace std;
//adjacency list
//adj[i] contains all neighbors of i
vector<int> adj[N];

//functions as defined above
int dp1[N], dp2[N];
vector<bool> fee(N, 0);
//pV is parent of node V
void dfs(int V, int pV)
{
    fee[V] = true;
    dp1[V] = 0;
    dp2[V] = 0;

    //traverse over all children
    for (auto v : adj[V])
    {
        if (v == pV)
            continue;

        dfs(v, V);
        dp2[V] += max(dp1[v], dp2[v]);
    }
    for (auto v : adj[V])
    {
        if (v == pV)
            continue;
        dp1[V] = max(dp1[V], 1 + dp2[V] + dp2[v] - max(dp1[v], dp2[v]));
    }
}

int main()
{
    int n, u, v;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (fee[i] != 1)
        {
            fee[i] = 1;
            memset(dp1, 0, sizeof(dp1));
            memset(dp2, 0, sizeof(dp2));
            dfs(i, 0);
            ans += (max(dp1[1], dp2[1]));
        }

    cout << ans << endl;
}