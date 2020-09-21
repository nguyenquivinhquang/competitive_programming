#include <bits/stdc++.h>
#define N 200005
//#define N 100
#define ll long long
#define pp pair<int, int>
#define Quyen "cute"
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define Quyen_reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("r", "input.txt", stdin);
#define output_file freopen("w", "output.txt", stdout);
using namespace std;
vector<int> edge[N];
int node[N], n, m, x, y, gone[N];
bool fee[N], stay[N];
void dfs(int u)
{
    for (auto v : edge[u])
    {
        if (stay[v] == false)
            continue;
        gone[v]++;
        if (gone[v] >= node[v] - gone[v])
        {
            stay[v] = false;
            dfs(v);
        }
    }
}
int main()
{
    Quyen_reset(stay, true);
    Quyen_reset(gone, 0);
    int u, v;
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        node[i] = edge[i].size();
        //cout << node[i] << " ";
    }
    stay[y] = false;
    dfs(y);

    if (stay[x] == true)
        cout << "stay";
    else
        cout << "leave";
}