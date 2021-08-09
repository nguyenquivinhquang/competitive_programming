#include <bits/stdc++.h>

#define  ll long long
#define pp pair<int, int>
const int N = 1001;

using namespace std;
int n, m, k;
vector<pp > edge[N];
pp query[N];
int short_path[N][N];

void dijkstra(int ss) {
    set<pp > q; // first:cost, second: edge;
    q.insert({0, ss});
    vector<int> d(n + 10, 1e9);
    d[ss] = 0;
    while (q.size() != 0) {
        auto u = q.begin()->second;
        q.erase(q.begin());
        for (auto e: edge[u]) {
            int v = e.first;
            int len = e.second;
            if (d[u] + len < d[v]) {
                q.erase({d[v], v});
                d[v] = d[u] + len;
                q.insert({d[v], v});
            }

        }
    }
    for (int i = 1; i <= n; i++)
        short_path[ss][i] = d[i];

}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    cin >> n >> m >> k;
    int u, v, c;
    vector<tuple<int, int, int>> edges;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> c;
        edge[u].push_back({v, c});
        edge[v].push_back({u, c});
        edges.emplace_back(u, v, c);
    }
    for (int i = 1; i <= k; i++) {
        cin >> u >> v;
        query[i] = {u, v};
    }
    //cout << "hi" << endl;
    for (int i = 1; i <= n; i++)
        dijkstra(i);
    /*for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int j = 1; j <= n; j++)
            cout << short_path[i][j] << " ";
        cout << '\n';
    }*/

    int ans = 1000000000;
    for (auto [u, v, w]: edges) {
        int tmp = 0;
        for (int i = 1; i <= k; i++) {
            auto [x, y] = query[i];

            int cs = short_path[x][y];
            cs = min(cs, short_path[x][u] + short_path[y][v]);
            cs = min(cs, short_path[x][v] + short_path[y][u]);

            tmp += cs;
        }
        ans = min(ans, tmp);
    }
    cout << ans << '\n';
}