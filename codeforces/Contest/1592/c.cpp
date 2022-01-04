#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000090;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, a[N], k, val[N];
vector<int> vertice[N];
ll sum = 0, cnt;
void dfs(int u, int preU) {
    for (auto v : vertice[u]) {
        if (v == preU) continue;
        dfs(v, u);
        val[u] ^= val[v];
    }
    if (val[u] == sum) {
        val[u] = 0;
        cnt++;
    }
}
void solve() {
    // memset(val, 0, sizeof(val));
    sum = cnt = 0;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        val[i] = a[i];
        sum ^= a[i];
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vertice[x].push_back(y);
        vertice[y].push_back(x);
    }
    if (sum == 0) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) vertice[i].clear();return;
    }
    if (k <= 2) {
        cout << "NO\n";
        for (int i = 1; i <= n; i++) vertice[i].clear();
        return;
    }

    dfs(1, 0);
    if (cnt > 1) {
        cout << "YES\n";
    } else cout << "NO\n";
    for (int i = 1; i <= n; i++) vertice[i].clear();
    

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
