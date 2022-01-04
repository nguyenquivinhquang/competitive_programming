#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;
int cond[N][N];
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vi vertice[N];
int n, cost[N];
int dfs(int u, int preU) {

    int cur_cost = 0;
    vector<int> c;
    for (auto v : vertice[u]) {
        if (v == preU) continue;
        c.push_back(dfs(v, u));
    }
    sort(c.begin(), c.end(), greater<int>());
    if (c.size() == 0) return cost[u];
    if (u != 1) return c[0] + cost[u];
    if (c.size() > 1) return c[0] + c[1] + cost[u];
    return c[0] + cost[u];
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> cost[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        vertice[u].push_back(v);
        vertice[v].push_back(u);
    }
    cout << dfs(1, -1) << "\n";
    for (int i = 1; i <= n; i++) vertice[i].clear();

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int test; cin >> test;
    for (int t = 1; t <= test; t++) {
        cout << "Case " << "#" << t << ": "; solve();
    }
}
