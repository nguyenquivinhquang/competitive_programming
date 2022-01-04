#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
const int N = 800009; 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, m;
vector<int> adj[N + 3];
int subtree_size[N + 3], color[N + 3];

int get_subtree_size(int node, int par = -1) {
	int& res = subtree_size[node];
	res = 1;
	for (int i : adj[node]) {
		if (i == par) continue;
		res += get_subtree_size(i, node);
	}
	return res;
}

int get_centroid(int node, int par = -1) {
	for (int i : adj[node]) {
		if (i == par) continue;

		if (subtree_size[i] * 2 > n) {
			return get_centroid(i, node);
		}
	}
	return node;
}
map<int,int> trace[N + 3], total_color;
int ans = 0;
bool dfs(int u, int preU) {
    
    for (auto v :adj[u]) {
        if (v == preU) continue;
        bool ok = dfs(v, u);
        if (ok) ans++;
        if (trace[u].size() > trace[v].size()) swap(trace[u], trace[v]);
        for (auto value: trace[v]) {
            trace[u][value.first] += value.second;
        }
        trace[v].clear();
    }
    
    bool check = true;
    trace[u][color[u]]++;
    for (auto v : trace[u]) {
        if (total_color[v.first] != v.second) {
            check = false;
            break;
        }
        cout << u << endl;
    }
    
    return check;
}

void solve() {
    memset(subtree_size, 0, sizeof(subtree_size));
    ans = 0; total_color.clear();
    cin >> n;
    cerr << "OK" << endl;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for (int i = 0; i < n; i++) {
        cin >> color[i];
        total_color[color[i]]++;
    }
   
    get_subtree_size(0);
    cerr << "ok" << endl;
    int root = get_centroid(0);
    
    dfs(root, -1);
    cout << ans << "\n";
    // cerr << ans << endl;
    for (int i = 0; i <= n + 2; i ++) {
        adj[i].clear();
        trace[i].clear();
    }
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
