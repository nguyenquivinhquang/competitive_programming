#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pp pair<int, int>
 
const int N = 100005;
 
using namespace std;
vector<pp> edge[N]; // {dest, weight}
int n,m, color[N];
bool cmp(pp x, pp y) {
    return x.first < y.first;
}
bool dfs(int u, int d) {    
    if (edge[u].size() > 1) {
        if (edge[u][0].first + edge[u][1].first < d) return false;
    }
    for (auto e : edge[u]) {
        int v = e.second, w = e.first;
        if (w >= d) continue;
        if (color[v] != 0) {
            if (color[v] == color[u]) return false;
            continue;
        }
       
        if (color[u] == 1) color[v] = 2;
        else color[v] = 1;
        
        bool check = true;
        check =  dfs(v, d);
        if (check == false) return false;
    }
    return true;
}
bool check(int d) {
    memset(color, 0, sizeof(color));
    for (int i = 1; i <= n; i++) {
        if (color[i] != 0) continue;
        color[i] = 1;
        if (dfs(i, d) == false) return false;
    }
    return true;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int weight, u, v;
        cin >> u >> v >> weight;
        u++,v++;
        edge[u].push_back({weight, v});
        edge[v].push_back({weight, u});  
    }
    ll l = 1, r = 2000000009;
    for (int i = 1; i <= n; i++) sort(edge[i].begin(), edge[i].end(), cmp);
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (check(mid) == false) r = mid - 1;
        else l = mid;
    }
    if (l >= 2000000009) cout <<"INF\n";
    else cout << l << "\n";
    for (int i = 1; i <= n; i++) edge[i].clear();
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        solve();
    }
}   