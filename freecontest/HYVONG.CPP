#include <bits/stdc++.h>

#define ll long long
#define pp pair<long long, long long>

const int N = 2000009;

using namespace std;

struct Vertice {
    ll v, cost, d;
};
int n, m, k1, k2, s, t, totalK, idS, idT;
vector<vector<int>> id[807];
bool fee[N];
vector<pp> vertice[N];
vector<Vertice> vTemp[900];
void build_graph(int u) {
    fee[u] = true;
    for (auto e : vTemp[u]) {
        ll v = e.v, len = e.cost, d = e.d;
        // if (fee[v]) continue;
        for (int i = 0; i <= k1 + 1; i++)
            for (int j = 0; j <= k2 + 1; j++) {
                int x = i, y = j;
                if (id[u][i][j] == 0) id[u][i][j] = ++totalK;
                int idU = id[u][i][j];
                if (d == 1) x++;
                if (d == 2) y++;
                // if (x > k1 + 1|| y > k2) continue;

                if (id[v][x][y] == 0) id[v][x][y] = ++totalK;
                int idV = id[v][x][y];

                vertice[idU].push_back({idV, len});
                vertice[idV].push_back({idU, len});
            }
    }
}
void dijsktra() {
    set<pp> q;
    vector<ll> d(N, 1e15);
    d[idS] = 0;
    q.insert({0, idS});
    while (q.size() != 0) {
        int u = q.begin()->second;
        q.erase(q.begin());
        for (auto e : vertice[u]) {
            ll v = e.first, len = e.second;
            if (d[u] + len < d[v]) {
                q.erase({d[v], v});
                d[v] = d[u] + len;
                q.insert({d[v], v});
            }
        }
    }
    if (d[idT] == 1e15) d[idT] = -1;
    cout << d[idT];
    // cout << -1;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    memset(fee, false, sizeof(fee));
    cin >> n >> m >> k1 >> k2;
    vector<int> temp(k2 + 3, 0);
    for (int i = 1; i <= n; i++) {
        id[i].resize(k1 + 3, temp);
    }
    totalK = 0;
    int x, y, c, d;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> c >> d;
        vTemp[x].push_back({y, c, d});
        vTemp[y].push_back({x, c, d});
    }
    cin >> s >> t;
    for (int i = 1; i <= n; i++) {
        // if (fee[i]) continue;
        build_graph(i);
    }
    memset(fee, false, sizeof(fee));
    idS = id[s][0][0];
    if (id[t][k1][k2] == 0) id[t][k1][k2] = ++totalK;
    idT = id[t][k1][k2];
    dijsktra();
    // cout << endl
    //      << idT;
}
