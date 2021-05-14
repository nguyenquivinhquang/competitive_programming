#include <bits/stdc++.h>

#define ll long long
#define pp pair<ll, ll>
#define int long long
const int N = 55;
const int inf = -923372036654775808;

using namespace std;

vector<pair<pp, int>> edge[N][N];
map<int, vector<int> > trace;
int n, m, k, b[N], d[N][N];
char a[N][N];
vector<int> total(N, inf), output[N];
int val_res = inf;

void build_graph() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'X')
                continue;
            if (a[i][j] == 'R' && j + 1 <= m)
                edge[i][j].push_back({make_pair(i, j + 1), 0});
            else if (a[i][j] == 'L' && j - 1 > 0)
                edge[i][j].push_back({make_pair(i, j - 1), 0});
            else if (a[i][j] == '?') {
                if (j - 1 > 0) edge[i][j].push_back({make_pair(i, j - 1), 0});
                if (j + 1 <= m) edge[i][j].push_back({make_pair(i, j + 1), 0});
            } else if (a[i + 1][j] != 'X' && i + 1 <= n && a[i][j] == '.')
                edge[i][j].push_back({make_pair(i + 1, j), 0});

        }
    for (int i = 1; i <= m; i++) {
        if (a[n][i] == '.')
            edge[n][i].push_back({{n + 1, i}, b[i]});
    }
}

void dijkstra(int ss) {
    for (int i = 1; i < N; i++)
        for (int j = 0; j < N; j++) d[i][j] = inf;
    set<pair<int, pp >, greater<pair<int, pp>>> q;
    d[1][ss] = 0;
    q.insert({0, {1, ss}});
    while (q.size() != 0) {
        pp temp = q.begin()->second;
        q.erase(q.begin());
        int u, v;
        for (auto e : edge[temp.first][temp.second]) {
            // pp to = edge.first;
            int len = e.second;
            tie(u, v) = e.first;
            if (d[temp.first][temp.second] + len > d[u][v]) {
                q.erase({d[u][v], e.first});
                d[u][v] = d[temp.first][temp.second] + len;
                q.insert({d[u][v], e.first});
            }
        }
    }
    int val = inf;
    for (int i = 1; i <= m; i++) {
        total[i] = max(total[i], d[n + 1][i]);
        val_res = max(val_res, total[i]);
        if (d[n + 1][i] >= 0)
            output[ss].push_back(i);
        //cout << d[n + 1][i] << " ";
    }
}

void dnq(int k) {

    if (trace[k].size() != 0)
        return;
//    if (k == 3)
//        cout << "de";
    vector<int> temp1, temp2, cur(N, inf);
    if (k % 2 == 0) {
        dnq(k / 2);
        temp1 = trace[k / 2];
        temp2 = temp1;
    } else {
        dnq(k / 2);
        dnq(k / 2 + 1);
        temp1 = trace[k / 2];
        temp2 = trace[k / 2 + 1];
    }
    for (int i = 1; i <= m; i++) {
        for (auto v: output[i]) {
            cur[v] = max(cur[v], temp1[i] + temp2[v]);
            if (cur[v] < 0) cur[v] = inf;
            val_res = max(val_res, cur[v]);
        }
    }
    trace[k] = cur;

}

void debug() {
    // print edge
    auto x = edge[2][3];
    for (auto v: x) {
        cout << v.first.first << " " << v.first.second << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int i = 1; i <= m; i++) cin >> b[i];
    build_graph();
    for (int i = 1; i <= m; i++) {
        dijkstra(i);
        //cout << "i \n";
    }
    //debug();

    trace[1] = total;

    dnq(k);
    vector<int> res = trace[k];

    for (int i = 1; i <= m; i++)
        val_res = max(res[i], val_res);
    if (val_res < 0) val_res = 0;
    cout << val_res << endl;

}