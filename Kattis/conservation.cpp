#include <bits/stdc++.h>
using namespace std;
 
int toposort(int n, vector<vector<int>> &adj, vector<int> &p, int lab) {
	vector<int> indeg(n);
	for (int i = 0; i < n; i++) {
		for (int v: adj[i]) indeg[v]++;
	}
 
	stack<int> st[2];
	for (int i = 0; i < n; i++) {
		if (indeg[i] == 0) {
			st[p[i]].push(i);
		}
	}
 
	int cnt = 0, ans = -1;
	while (cnt < n) {
		while (st[lab].size()) {
			int u = st[lab].top(); st[lab].pop(); cnt++;
 
			for (int v: adj[u]) {
				indeg[v]--;
				if (indeg[v] == 0) {
					st[p[v]].push(v);
				}
			}
		}
 
		lab ^= 1; ans++;
	}
	return ans;
}
 
void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i]; p[i]--;
	}
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
	}
 
	cout << min(toposort(n, adj, p, 0), toposort(n, adj, p, 1)) << '\n';
}
 
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
 
	int t; cin >> t;
	while (t--) {
		solve();
	}
 
	return 0;
}