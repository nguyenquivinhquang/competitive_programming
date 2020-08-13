#include <bits/stdc++.h>
#define N 200005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
set<int> diff[N];
int n, x, y, color[N];
vector<int> tree[N];

void dfs(int u, int preu)
{

    for (auto v : tree[u])
        if (v != preu)
        {
            dfs(v, u);
            if (diff[u].size() < diff[v].size())
                swap(diff[u], diff[v]);
            for (auto t : diff[v])
                diff[u].insert(t);
            diff[v].clear();
        }
    color[u] = diff[u].size();
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> color[i];
        diff[i].insert(color[i]);
    }
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        cout << color[i] << " ";
}
int main()
{
    fastio;
    solve();
}