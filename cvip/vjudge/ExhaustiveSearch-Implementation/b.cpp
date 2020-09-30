#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;
int n, m;
set<int> l[N], r[N];
vector<pp> init;
vector<int> trace;
set<int> vertice[N];
bool fee[N], check = false;
void dfs(int u, int d)
{
    if (d > n + 2)
        return;
    if (d == n + 2 && u == 2)
        check = true;
    for (auto v : vertice[u])
    {
        if (fee[v] == true)
            continue;
        fee[v] = true;
        trace.push_back(v);
        dfs(v, d + 1);
        trace.pop_back();
        fee[v] = false;
    }
}
void solve()
{
    init.clear();
    int x, y;
    cin >> m;
    m += 2;
    check = false;
    reset(fee, false);
    fee[1] = true;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        init.push_back({x, y});
        l[x].insert(i), l[y].insert(i);
    }
    for (int i = 0; i < m; i++)
    {
        int u = init[i].second;
        for (auto v : l[u])
        {
            vertice[i + 1].insert(v);
        }
        u = init[i].first;
        for (auto v : l[u])
        {
            vertice[i + 1].insert(v);
        }
    }
    dfs(1, 1);
    for (int i = 0; i <= m; i++)
    {
        //cout << i << ": ";
        for (auto v : vertice[i])
            cout << i << " " << v << "\n";
        cout << endl;
    }
    if (check == true)
        cout << "YES\n";
    else
        cout << "NO\n";
    for (int i = 1; i <= m; i++)
        vertice[i].clear();
    for (int i = 1; i <= N; i++)
        l[i].clear();
    init.clear();
}
int main()
{

    // input_file;
    // output_file;
    //fastio;
    while (1 == 1)
    {
        cin >> n;
        if (n == 0)
            return 0;
        solve();
    }
}