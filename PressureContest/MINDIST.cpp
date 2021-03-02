#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pp pair<int, int>

#define inputFile "MINDIST.INP"
#define outputFile "MINDIST.OUT"
using namespace std;
const int N = 500;
const int inf = 1000000 - 1;
int d[N][N];
void reset() {
    for (int i = 0; i <= 100; i ++)
        for (int j = 0; j <= 100; j++)
            d[i][j] = inf;
}
void solve() {
    reset();
    map<int, int> edge[N];
    int m, x, y, c, n;
    cin >> n >> m;
    bool check = true;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> c;
        d[x][y] = d[y][x] = c;
        if (edge[x][y] != 0 && edge[x][y] != c) check = false;
        edge[x][y] = edge[y][x] = c;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    vector<pair<ll, pp>> res;
    bool fee[N][N];
    memset(fee, false, sizeof(fee));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (d[i][j] != edge[i][j] && edge[i][j] != 0 || check == false) {
                cout << "-1\n";
                return;
            } else if (fee[i][j] == false && fee[j][i] == false && i != j) {
                fee[i][j] = fee[j][i] = true;
                res.push_back({d[i][j], {i, j}});

            }
    cout << res.size() << "\n";
    for (auto v : res) {
        cout << v.second.first << " " << v.second.second << " " << v.first << "\n";
    }
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    freopen(inputFile, "r", stdin);
    freopen(outputFile, "w", stdout);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        solve();
    }

}
