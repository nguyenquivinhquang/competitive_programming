#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 100009;
const int Mod = 1e9 + 7;
using namespace std;
int n, m, total_sink[N];
vector<int> vertice[N];
set<int> trace[N];
ll bfs() {
    vector<int> d(n + 10, 0);
    vector<bool> fee(N + 10, false);
    queue<int> q;

    for (int i = 1; i <= n; i++)
        if (total_sink[i] == 0) q.push(i);

    d[1] = 1;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto v : vertice[u]) {
            d[v] = (d[v] + d[u]) % Mod;
            total_sink[v]--;
            if (total_sink[v] == 0)
                q.push(v);
            fee[v] = true;
        }
    }
    return d[n];
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int x, y;
    cin >> n >> m;
    memset(total_sink, 0, sizeof(total_sink));
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        vertice[x].push_back(y);
        trace[x].insert(y);
        total_sink[y]++;
        auto it = trace[y].lower_bound(x);
        if (*it == x) {
            total_sink[x]--, total_sink[y]--;
        }
    }
    cout << bfs();
}