#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define int long long
const ll INF = 1e18;

vector<ll> dijkstra(int n, vector<vector<pii>> adj, int s) {
    vector<ll> dist(n+1, INF);
    vector<bool> vis(n+1);
    dist[s] = 0;
    priority_queue<pair<long long, int>> pq;
    pq.push({0, s});

    while (pq.size()) {
        auto [we, now] = pq.top(); pq.pop();
        if (vis[now]) continue;
        vis[now] = 1;

        for (auto [u, w]: adj[now]) {
            if (dist[u] > dist[now] + w) {
                dist[u] = dist[now] + w;
                pq.push({-dist[u], u});
            }
        }
    }
    return dist;
}

void solve(int n, int m) {
    int h1, s1, h2, s2; cin >> h1 >> s1 >> h2 >> s2;
    vector<tuple<int, int, int>> edges;
    vector<vector<pii>> g(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    vector<ll> dh1 = dijkstra(n, g, h1);
    vector<ll> ds1 = dijkstra(n, g, s1);
    vector<ll> dh2 = dijkstra(n, g, h2);
    vector<ll> ds2 = dijkstra(n, g, s2);
    int ans1 = dh1[s1], ans2 = dh2[s2];

    // can they use any edge in common?
    for (auto [u, v, w]: edges) {
        if (dh1[u] == dh2[u]) {
            int d1 = dh1[u] + ds1[v] + w;
            int d2 = dh2[u] + ds2[v] + w;

            if (d1 == ans1 && d2 == ans2) {
                cout << "-1\n"; return;
            }
        }
    }
    for (auto [v, u, w]: edges) {
        if (dh1[u] == dh2[u]) {
            int d1 = dh1[u] + ds1[v] + w;
            int d2 = dh2[u] + ds2[v] + w;

            if (d1 == ans1 && d2 == ans2) {
                cout << "-1\n"; return;
            }
        }
    }

    int ans = 0;
    // can they cross path at an edge?
    for (auto [u, v, w]: edges) {
        int d1 = dh1[u] + ds1[v] + w;
        int d2 = dh2[v] + ds2[u] + w;

        if (d1 == ans1 && d2 == ans2) {
            // do they intersect strictly???
            int l1 = dh1[u], r1 = dh1[v];
            int l2 = dh2[v], r2 = dh2[u];

            int l = max(l1, l2), r = min(r1, r2);
            if (l < r) ans++;
        }
    }
    for (auto [v, u, w]: edges) {
        int d1 = dh1[u] + ds1[v] + w;
        int d2 = dh2[v] + ds2[u] + w;

        if (d1 == ans1 && d2 == ans2) {
            // do they intersect strictly???
            int l1 = dh1[u], r1 = dh1[v];
            int l2 = dh2[v], r2 = dh2[u];

            int l = max(l1, l2), r = min(r1, r2);
            if (l < r) ans++;
        }
    }

    // can they use any nodes in common?
    for (int i = 1; i <= n; i++) {
        if (i == s1 || i == s2) continue;

        int d1 = dh1[i] + ds1[i];
        int d2 = dh2[i] + ds2[i];

        if (dh1[i] == dh2[i] && d1 == ans1 && d2 == ans2) {
            ans++;
        }
    }

    // can they use either s1 or s2
    if (s1 == s2) {
        ans++;
    } else {
        // can they meet at s1?
        {
            int d1 = ans1;
            int d2 = dh2[s1] + ds2[s1];

            if (d2 == ans2 && dh2[s1] >= d1) {
                ans++;
            }
        }

        // can they meet at s2
        {
            int d2 = ans2;
            int d1 = dh1[s2] + ds1[s2];

            if (d1 == ans1 && dh1[s2] >= d2) {
                ans++;
            }
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    while (cin >> n >> m, n, m) {
        solve(n, m);
    }

    return 0;
}