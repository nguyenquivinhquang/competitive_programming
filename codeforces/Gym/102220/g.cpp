#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;

vector<long long> adj[100001];

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
	}
	for (int i = 1; i < n; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back(w);
		adj[v].push_back(w);
	}
	long long ans = 0;
	for (int u = 1; u <= n; u++) {
		sort(adj[u].begin(), adj[u].end());

		for (long long j: adj[u]) {
			ans += adj[u][0];
			ans += j;
		}
		ans -= 2*adj[u][0];
	}
	cout << ans << '\n';
}

signed main()
{
	fastio;
	int testcase; cin >> testcase;
	while (testcase--) {
		solve();
	}
}