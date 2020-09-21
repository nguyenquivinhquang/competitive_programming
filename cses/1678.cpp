#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(a, val) memset(a, val, sizeof(a));
#define modulo int(1e9 + 7)
#define endl '\n'
using namespace std;
int n, m, pre[N], step[N];
vector<int> edge[N];
bool fee[N], ex = false;
vector<int> trace;
void answer(int u, int v)
{
    ex = true;
    if (!trace.size())
        trace.clear();
    trace.push_back(u);
    while (v != u)
    {
        trace.push_back(v);
        v = pre[v];
    }
    trace.push_back(u);
}
void dfs(int u, int preU)
{
    for (auto v : edge[u])
    {
        if (ex == true)
            return;
        if (step[u] == step[v])
        {
            if (v == preU)
            {
                pre[v] = u, pre[u] = v;
            }
            answer(v, u);
            return;
        }

        if (fee[v] == true)
            continue;
        fee[v] = true;
        pre[v] = u;
        step[v] = step[u];
        dfs(v, u);
    }
    step[u] = -1;
}
int main()
{
    int x, y;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
    }
    reset(step, 0);
    reset(fee, false);
    reset(pre, -1);
    for (int i = 1, s = 0; i <= n; i++)
    {
        if (fee[i] == false)
        {
            fee[i] = true;
            step[i] = ++s;
            dfs(i, -1);
        }
    }
    if (trace.size() != 0)
    {
        reverse(trace.begin(), trace.end());
        cout << trace.size() << endl;
        for (auto v : trace)
            cout << v << " ";
    }
    else
        cout << "IMPOSSIBLE";
}