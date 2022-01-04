#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
const int N = 400009;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vector<int> vertice[N];
int n, k;
set<int> leaf;
int father[N], count_child[N], ok[N];
void dfs(int u, int preU) {
    father[u] = preU;
    if (vertice[u].size() == 1) {
        // this is the leaf
        leaf.insert(u);
        // return;
    }
    for (auto v : vertice[u]) {
        if (v == preU) continue;
        count_child[u]++;
        dfs(v, u);
    }
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        vertice[u].push_back(v);
        vertice[v].push_back(u);
        father[i] = -1;
        count_child[i] = 0;
        ok[i] = false;
    }
    if (n == 1) {
        cout << "0\n";
        return;
    }
    count_child[n] = 0;
    ok[n] = false;
    father[n] = -1;
    dfs(1, -1);
    if (father[1] == -1) father[1] = vertice[1][0];
    int res = n;
    for (auto v : leaf) ok[v] = true;
    for (int i = 1; i <= k; i++) {
        set<int> temp;
        
        res -= leaf.size();
        if (res == 0) break;
        for (auto v: leaf) {
            if (father[v] == -1) continue;
            count_child[father[v]]--;
            auto it = leaf.lower_bound(father[v]);
            if (ok[father[v]] == false && count_child[father[v]] < 2) {
                temp.insert(father[v]);
                ok[father[v]] = true;
            }
        }
        leaf = temp;
        
    }
    cout << res << "\n";
    for (int i = 1; i <= n; i++) vertice[i].clear();
    leaf.clear();
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}