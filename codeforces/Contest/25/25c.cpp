#include<bits/stdc++.h>
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 305;
int n, k;
int dist[N][N];
signed main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin.exceptions(cin.failbit);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> dist[i][j];
    int u, c, v;
    cin >> k;
    while (k--) {
        cin >> u >> v >> c;
        dist[u][v] = dist[v][u] = min(dist[u][v], c);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                dist[j][i] = dist[i][j] = min(dist[i][j], dist[i][u] + dist[u][v] + dist[v][j]);
                dist[j][i] = dist[i][j] = min(dist[i][j], dist[i][v] + dist[u][v] + dist[u][j]);

        }
        int res = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                res += dist[i][j];
        cout << res / 2 << " ";
    }
}

