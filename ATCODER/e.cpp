#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;
const int INF = 1000000000;

using namespace std;

vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d) {
    int n = adj.size();
    d.assign(n, INF);
   

    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
}
int h, w;
char town[N][N];
int get_vertice(int x, int y) {
    return h * x + y;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> h >> w;
    adj.resize(h * w + 3);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
           cin >> town[i][j];
        }
    }
    for (int i = 0; i < h; i++) 
        for (int j = 0; j < w; j++) 
            for (int x = - 1; x <= 1; x++ ) {
                for (int y = - 1; y <= 1; y++) {
                    if (x == 0 && y == 0 || x * y != 0) continue;
                    if (i + x < 0 || y + x >= h || j + y < 0 || j + y >= w) continue;
                    int v = get_vertice(i + x, j + y), u = get_vertice(i,j);
                    int cost = 0; if (town[i][j] == '#') cost = 1;
                    adj[u].push_back({v, cost });
                }
            }
    vector<int> res(h * w + 10);
    cout << res.size() << endl;
    dijkstra(h*w-1, res);
    // for (auto v : res ) cout << v << " ";
    cout << res[h*w-1];
}
