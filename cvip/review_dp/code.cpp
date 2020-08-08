#include <bits/stdc++.h>
#define maxn 100

using namespace std;
vector<int> vertice[maxn], cycle;
int n, m, level[maxn], independent[maxn];
void dfs(int u)
{
    for (auto v : vertice[u])
        if (level[v] != -1 && u != v)
        {
            
        }
}
int main()
{
    int u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        vertice[u].push_back(v);
        vertice[v].push_back(u);
        level[i] = -1;
    }
}