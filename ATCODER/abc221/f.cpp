#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 400000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vector<pii> vertice[N]; // dest, cost
long long cost[N], dp1[N], dp2[N];
int n;
multiset<pair<int, int>, greater<pair<int, int>>> trace[N];

ll dfs1(int u, int preU, int x) {
    for (auto e : vertice[u]) {
        int v = e.first, co = e.second;
        if (v == preU) continue;
        ll temp =  dfs1(v, u, co);
        dp1[u] = max(dp1[u], temp);
        trace[u].insert({temp, v});
    }
    return max(cost[u] + x, dp1[u] + x);
}
void dfs2(int u, int preU, int x) {
    int t = -1;
    for (auto c : trace[preU]) {
        t = c.first;
        if (c.second != u)
            break;
    }
    if (t != -1) trace[u].insert({t + x, preU});

    for (auto e : vertice[u])
    {
        auto v = e.first, co = e.second;
        if (v == preU)
            continue;
        dfs2(v, u, co);
    }
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
   
    for (int i = 1; i < n; i++) {
        int u, v, c; cin >> u >> v >> c;
        vertice[u].push_back({v,c});
        vertice[v].push_back({u, c});
    }
     for (int i = 1; i <= n; i++) cin >> cost[i];
    
    dfs1(1, 0,0);
    trace[0].insert({cost[1], -1});
    dfs2(1,0, 0);
    for (int i = 1; i <= n; i++){
        auto t = *trace[i].begin();
        cout << max(dp1[i], t.first) << "\n";
    }
}
