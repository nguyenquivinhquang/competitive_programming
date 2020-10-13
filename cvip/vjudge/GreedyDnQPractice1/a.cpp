#include <bits/stdc++.h>
#define N 100005
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
vector<int> edge[N];
int main()
{
    cin >> n >> m;
    int x, y, d[N];
    bool fee[N];
    reset(fee, true);
    reset(d, 0);
    queue<int> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    q.push(1);
    d[1] = 1;
    while (q.size() != 0)
    {
        int u = q.front();
        q.pop();
        for (auto v : edge[u])
        {
            if (fee[v] == false)
                continue;
            fee[v] = false;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    cout << d[n] - 2;
}