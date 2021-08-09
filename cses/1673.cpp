//https://cses.fi/problemset/task/1673
#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>
#define int long long
const int N = 1000;
const int INF = 1e18;
using namespace std;
struct edge {
    int a, b, cost;
    edge(int x, int y, int z) {
        a = x, b = y, cost = z;
    }
};
bool cmp(edge& a, edge& b) {
    if (a.a == b.a)
        return a.b < b.b;
    return a.a < b.a;
}
int n, m, v;
vector<edge> e;
void solve() {
    vector<int> d(n, INF);
    d[0] = 0;
    vector<int> p(n, 0);
    sort(e.begin(), e.end(), cmp);
    int x = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost) {
                    d[e[j].b] = max(-INF, d[e[j].a] + e[j].cost);
                }
    }
    // for (auto v : d)
    //   cout << v << " ";
    // cout << endl;
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost) {
                    d[e[j].b] = -INF;
                    p[e[j].b] = 1;
                }
    if (p[n - 1])
        cout << -1;
    else
        cout << -d[n - 1];
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int x, y, w;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        w *= -1;
        e.push_back(edge(x - 1, y - 1, w));
        // e.push_back(edge(y -1, x -1, w));
    }
    solve();
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/