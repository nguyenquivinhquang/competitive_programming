#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
struct edge {
    int a, b, cost;
};

int n, m, q, s;
vector<edge> e;
const int INF = 1e18;
vector<bool> inf;
vector<int> d;
bool cmp(edge& a, edge& b) {
    if (a.a == b.a)
        return a.b < b.b;
    return a.a < b.a;
}
void solve() {
    
    d[s] = 0;
    sort(e.begin(), e.end(), cmp);
    for (int i=0; i<n-1; ++i)
        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF && d[e[j].b] > d[e[j].a] + e[j].cost)
                d[e[j].b] = max(-INF,  d[e[j].a] + e[j].cost);
    for (int i=0; i<n-1; ++i)
        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF && d[e[j].b] > d[e[j].a] + e[j].cost ) {
                inf[e[j].b] = true;
                d[e[j].b] = -INF;
            }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    while (cin >> n  >> m >> q >> s) {
        if (n + m + q + s == 0) break;
        int x, y, w;
        e.clear();
    
        for (int i = 1; i <= m; i++) {
            cin >> x  >> y >> w;
            edge _edge = {x, y, w};
            e.push_back(_edge);
        }
        
        inf.clear();inf.resize(n, false);
        d.clear() , d.resize(n, INF);
        
        solve();
        while (q --) {
            int u;
            cin >> u;
            if (u == s) cout <<"0\n"; else
            if (d[u] == INF) cout << "Impossible\n";
            else if (inf[u] == true) cout << "-Infinity\n";
            else cout << d[u] << "\n";
        }
        cout << "\n";
    }
}
