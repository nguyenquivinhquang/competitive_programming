#include <bits/stdc++.h>
#define maxn 200001
using namespace std;
int n, d1[maxn], d2[maxn], res[maxn], node, x_max = 0;
vector<int> vertice[maxn];
multiset<pair<int, int>, greater<pair<int, int>>> trace[maxn];
void dfs1(int u, int preU, int x)
{
    d1[u] = 1;

    for (auto v : vertice[u])
    {
        if (v == preU)
            continue;
        dfs1(v, u, x + 1);
        d1[u] = max(d1[u], d1[v] + 1);
        trace[u].insert({d1[v] + 1, v});
    }
}
void dfs2(int u, int preU, int x)
{
    int t = -1;
    for (auto c : trace[preU])
    {
        t = c.first;
        if (c.second != u)
            break;
    }
    trace[u].insert({t + 1, preU});
    for (auto v : vertice[u])
    {

        if (v == preU)
            continue;
        dfs2(v, u, 1);
    }
}
void debug()
{
    for (int i = 1; i <= n; i++)
        cout << d1[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << d2[i] << " ";
}
int main()
{
    int x, y;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        vertice[x].push_back(y);
        vertice[y].push_back(x);
    }
    dfs1(1, 0, 1);
    trace[1].insert({1, 1});
    dfs2(1, 0, 1);
    //debug();
    for (int i = 1; i <= n; i++)
    {
        auto t = *trace[i].begin();
        cout << t.first - 1 << " ";
    }
}