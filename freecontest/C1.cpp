#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
vector<int> edge[N];
int n, color[N];
map<int, int> res[N], trace;

void dfs(int u, int preU)
{
    int c = 1;
    for (auto v : edge[u])
        if (v != preU)
        {
            if (c == color[u])
                c++;
            trace[c] = 1;
            color[v] = c;
            res[u][v] = c;
            res[v][u] = c;
            dfs(v, u);
            c++;
        }
}
int main()
{

    vector<pp> query;
    reset(color, 0);
    int x, y;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
        query.push_back({x, y});
    }
    dfs(1, 0);
    cout << trace.size() << endl;
    for (auto u : query)
    {
        x = u.first, y = u.second;
        cout << res[x][y] << endl;
    }
}