#pragma GCC optimize("Ofast")
#pragma GCC target ("avx,avx2")
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;

int n, q;
vector<int> adj[MAXN];

void input() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

int lv[MAXN], pr[MAXN];
long long w[MAXN];

void dfs(int now, int prev, int h) {
	pr[now] = prev;
	lv[now] = h;

	for (int u: adj[now]) {
		if (u != prev) dfs(u, now, h+1);
	}
}

void add_path(int u, int v, int k) {
	int h1 = lv[u], h2 = lv[v];
	while (h1 > h2) {
		w[u] += k;
		u = pr[u];
		h1--;
	}
	while (h2 > h1) {
		w[v] += k;
		v = pr[v];
		h2--;
	}
	while (u != v) {
		w[u] += k;
		w[v] += k;
		u = pr[u]; v = pr[v];
	}
	w[u] += k;
}

void xor_path(int u, int v, int k) {
	int h1 = lv[u], h2 = lv[v];
	while (h1 > h2) {
		w[u] ^= k;
		u = pr[u];
		h1--;
	}
	while (h2 > h1) {
		w[v] ^= k;
		v = pr[v];
		h2--;
	}
	while (u != v) {
		w[u] ^= k;
		w[v] ^= k;
		u = pr[u]; v = pr[v];
	}
	w[u] ^= k;
}

void minus_path(int u, int v, int k) {
	int h1 = lv[u], h2 = lv[v];
	while (h1 > h2) {
		w[u] = (w[u] < k ? w[u] : w[u] - k);
		u = pr[u];
		h1--;
	}
	while (h2 > h1) {
		w[v] = (w[v] < k ? w[v] : w[v] - k);
		v = pr[v];
		h2--;
	}
	while (u != v) {
		w[u] = (w[u] < k ? w[u] : w[u] - k);
		w[v] = (w[v] < k ? w[v] : w[v] - k);
		u = pr[u]; v = pr[v];
	}
	w[u] = (w[u] < k ? w[u] : w[u] - k);
}

long long sum_path(int u, int v) {
	int h1 = lv[u], h2 = lv[v];
	long long ans = 0;
	while (h1 > h2) {
		ans += w[u];
		u = pr[u];
		h1--;
	}
	while (h2 > h1) {
		ans += w[v];
		v = pr[v];
		h2--;
	}
	while (u != v) {
		ans += w[u];
		ans += w[v];
		u = pr[u]; v = pr[v];
	}
	ans += w[u];
	return ans;
}

long long xor_sum(int u, int v) {
	int h1 = lv[u], h2 = lv[v];
	long long ans = 0;
	while (h1 > h2) {
		ans ^= w[u];
		u = pr[u];
		h1--;
	}
	while (h2 > h1) {
		ans ^= w[v];
		v = pr[v];
		h2--;
	}
	while (u != v) {
		ans ^= w[u];
		ans ^= w[v];
		u = pr[u]; v = pr[v];
	}
	ans ^= w[u];
	return ans;
}

const long long INF = 1e18;

long long max_min(int u, int v) {
	int h1 = lv[u], h2 = lv[v];
	long long mx = 0, mn = INF;
	while (h1 > h2) {
		mx = (w[u] > mx ? w[u]: mx);
		mn = (w[u] < mn ? w[u]: mn);
		u = pr[u];
		h1--;
	}
	while (h2 > h1) {
		mx = (w[v] > mx ? w[v]: mx);
		mn = (w[v] < mn ? w[v]: mn);
		v = pr[v];
		h2--;
	}
	while (u != v) {
		mx = (w[u] > mx ? w[u]: mx);
		mn = (w[u] < mn ? w[u]: mn);
		mx = (w[v] > mx ? w[v]: mx);
		mn = (w[v] < mn ? w[v]: mn);
		u = pr[u]; v = pr[v];
	}
	mx = (w[u] > mx ? w[u]: mx);
	mn = (w[u] < mn ? w[u]: mn);
	return mx-mn;
}

long long min_abs(int u, int v, int k) {
	int h1 = lv[u], h2 = lv[v];
	long long ans = INF;
	while (h1 > h2) {
		ans = (abs(w[u] - k) < ans ? abs(w[u] - k) : ans);
		u = pr[u];
		h1--;
	}
	while (h2 > h1) {
		ans = (abs(w[v] - k) < ans ? abs(w[v] - k) : ans);
		v = pr[v];
		h2--;
	}
	while (u != v) {
		ans = (abs(w[u] - k) < ans ? abs(w[u] - k) : ans);
		ans = (abs(w[v] - k) < ans ? abs(w[v] - k) : ans);
		u = pr[u]; v = pr[v];
	}
	ans = (abs(w[u] - k) < ans ? abs(w[u] - k) : ans);
	return ans;
}

void solve() {
	for (int i = 1; i <= n; i++) {
		w[i] = 0;
	}
	dfs(1, 0, 1);

	/*cout << "HLD order:\n";
	for (int i = 1; i <= n; i++) {
		cout << i << ' ' << id[i] << '\n';
	}
	cout << "Solving queries\n";*/

	while (q--) {
		int tp; cin >> tp;
		int u, v; cin >> u >> v;

		//cout << u << ' ' << v << '\n';
		if (tp == 1) {
			int k; cin >> k;
			add_path(u, v, k);
		} else if (tp == 2) {
			int k; cin >> k;
			xor_path(u, v, k);
		} else if (tp == 3) {
			int k; cin >> k;
			minus_path(u, v, k);
		} else if (tp == 4) {
			cout << sum_path(u, v) << '\n';
		} else if (tp == 5) {
			cout << xor_sum(u, v) << '\n';
		} else if (tp == 6) {
			cout << max_min(u, v) << '\n';
		} else {
			int k; cin >> k;
			cout << min_abs(u, v, k) << '\n';
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int testcase; cin >> testcase;
	while (testcase--) {
		input();
		solve();
	}
}
