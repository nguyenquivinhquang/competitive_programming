#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
ll n, m;
vector<int> edge[N];
int fee[N];
vector<int> ans;
void dfs(int u)
{
    fee[u] = 1;
    for (auto v : edge[u])
    {
        if (!fee[v])
            dfs(v);
        else if (fee[v] == 1)
        {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
    }
    fee[u] = 2;
    ans.push_back(u);
}
int main()
{
    reset(fee, 0);
    int x, y;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!fee[i])
        {
            dfs(i);
        }
    }
    // check impossible
    reverse(ans.begin(), ans.end());
    for (int i : ans) cout << i << ' ';
}