#include <bits/stdc++.h>
#define maxn 100000

using namespace std;
vector<int> a[maxn];

int testcase, n = 0, queries, d[maxn], root[maxn];

void reset()
{

    memset(root, 0, sizeof(root));
    memset(d, 0, sizeof(d));
}
void find_level(int u, int level)
{
    for (auto v : a[u])
    {
        d[v] = level + 1;
        find_level(v, level + 1);
    }
}
int lca(int u, int v)
{
    while (d[u] != d[v])
    {
        if (d[u] > d[v])
            u = root[u];
        else
            v = root[v];
    }
    while (u != v)
    {
        u = root[u];
        v = root[v];
    }
    return v;
}
int main()
{
    cin >> testcase;
    for (int t = 1; t <= testcase; t++)
    {

        cout << "Case " << t << ": " << endl;
        reset();
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int m, temp;
            cin >> m;
            for (int j = 1; j <= m; j++)
            {
                cin >> temp;
                a[i].push_back(temp);
                root[temp] = i;
            }
        }

        d[1] = 1, root[1] = 1;
        find_level(1, 1);
        //debug();
        cin >> queries;
        int u, v;
        while (queries--)
        {
            cin >> u >> v;
            cout << lca(u, v) << endl;
        }
        for (int i = 1; i <= n; i++)
            a[i].clear();
    }
}