#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;
vector<int> vertice[maxn];
int n, query, root[maxn], d[maxn], max_road, min_road;
map<int, int> len[maxn];
void find_level(int u, int level, int preu)
{
    for (auto v : vertice[u])
        if (v != preu)
        {
            d[v] = level + 1;
            find_level(v, level + 1, u);
        }
}
void lca(int u, int v)
{
    while (d[u] != d[v])
    {
        if (d[u] > d[v])
        {
            int t = len[u][root[u]];
            max_road = max(max_road, t);
            min_road = min(min_road, t);
            u = root[u];
        }
        else
        {
            int t = len[v][root[v]];
            max_road = max(max_road, t);
            min_road = min(min_road, t);
            v = root[v];
        }
    }
    while (u != v)
    {
        int t = len[u][root[u]];
        max_road = max(max_road, t);
        min_road = min(min_road, t);
        u = root[u];
        t = len[v][root[v]];
        max_road = max(max_road, t);
        min_road = min(min_road, t);
        v = root[v];
    }
    cout << min_road << " " << max_road << endl;
}
void debug()
{
    for (int i = 1; i <= n; i++)
    {
        cout << root[i] << " ";
    }
}
void find_root(int u)
{

}
int main()
{
    int x, y, c;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y >> c;
        vertice[x].push_back(y);
        vertice[y].push_back(x);
        len[x][y] = c;
        len[y][x] = c;
    }
    root[1] = 1, d[1] = 1;
    cout << "Ha";
    debug();
    find_level(1, 1, -1);

    cin >> query;
    for (int i = 1; i <= query; i++)
    {
        min_road = 1e9, max_road = -1e9;
        cin >> x >> y;
        lca(x, y);
    }
}
#include <bits/stdc++.h>
#define ll long long
#define maxn 1000
using namespace std;
struct trie
{
    bool last;
    char n[27];
};
int main()
{
    int a[maxn];
    int *p = a;
    a[0] = 1;
    a[5] = 3;
    trie *t;
    //int *aa;
    //int *aa = 1;
    t->n[0] = '1';
    //cout << *(p + 5);
    cout << t ->n[0];
}