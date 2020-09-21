#include <bits/stdc++.h>
#define N 100009
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
int n, m, drone;
vector<int> edge[N];
bool fee[N], placed[N];
void dfs(int u)
{
    fee[u] = true;
    bool check = true;
    for (auto v : edge[u])
    {
        if (placed[v] == true)
            check = false;
    }
    placed[u] = check;
    for (auto v : edge[u])
    {
        if (fee[v] == false)
            dfs(v);
    }
}
int main()
{
    int d;
    Quyen_reset(fee, false);
    Quyen_reset(placed, false);
    cin >> drone >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> d;
        for (int j = 1; j <= d; j++)
        {
            cin >> m;
            edge[i].push_back(m);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (fee[i] == false)
            dfs(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (placed[i])
            drone--;
    }
    if (drone <= 0)
        cout << "possible";
    else
        cout << "impossible";
}