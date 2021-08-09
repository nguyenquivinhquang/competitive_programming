#include <bits/stdc++.h>
#define N 200005
#define long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(a, val) memset(a, val, sizeof(a))
#define modulo int(1e9 + 7)
#define endl '\n'
using namespace std;
int n, m, pre[N];
bool fee[N];
queue<int> s;
vector<int> edge[N];

void bfs()
{
    reset(fee, 1);
    reset(pre, -1);
    fee[1] = 0;
    s.push(1);
    while (s.empty() != 1)
    {
        int u = s.front();
        s.pop();
        //cout << u << " ";
        for (int v : edge[u])
        {
            if (fee[v] == 0)
                continue;
            s.push(v);
            fee[v] = 0;
            pre[v] = u;
        }
    }
}
void print_path()
{
    int v = n;
    vector <int> path;
    while (pre[v] != -1)
    {
        path.push_back(v);
        v = pre[v];
    }
    if (path.size() == 0)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        path.push_back(1);
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (int i : path)
            cout << i << " ";

    }
}
int main()
{
    int x, y;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    bfs();
    print_path();
}