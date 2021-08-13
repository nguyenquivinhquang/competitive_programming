#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

int n, m, dist[N][N];
char cell[N][N];
deque<pp> q;
void add_vertex(int u, int v, int cost, int val) {
    if (dist[u][v] > cost + val) {
        if (val == 1) q.push_back({u,v});
        else q.push_front({u,v});
        dist[u][v] = val + cost;
    }
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> cell[i][j];
    memset(dist, 127, sizeof(dist));
    q.push_back({1,1}); 
    dist[1][1] = 0;
    while (q.size()) {
        int u = q.front().first, v = q.front().second;
        q.pop_front();
         for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (u+dx < 1 || u + dx > n) continue;
                if (v+dy < 1 || v + dy > m || abs(dx) == abs(dy)) continue;
                if (cell[u+dx][v+dy]=='#') continue;
                int x = u + dx, y = v + dy;
                add_vertex(x, y, dist[u][v], 0);
            }
        }
        for (int dx = -2; dx <= 2; dx++) {
            if (u+dx < 1 || u + dx > n) continue;
            for (int dy = -2; dy <= 2; dy++) {
                if (v+dy < 1 || v + dy > m || abs(dx) + abs(dy) > 3 || dx == dy) continue;
                int x = u + dx, y = v + dy;
                add_vertex(x, y, dist[u][v], 1);
            }
        }
        // cout << q.size() << endl;
    }
    cout << dist[n][m];
    
}
