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

struct condensation_graph_maker{
	int n;
	vector<vector<int>> adj;
	vector<int> low;
	vector<int> num;
	vector<int> scc;
	int t = 0;
	stack<int> st;
	int scccount = -1;

	void init_graph(int n, vector<pair<int, int>> edges) {
		this->n = n;
		adj.resize(n);
		low.resize(n);
		num.resize(n);
		scc.resize(n);

		for (auto [x, y]: edges) {
			adj[x].push_back(y);
		}
	}

	void dfs(int now) {
		t++;
		low[now] = t;
		num[now] = t;
		st.push(now);
		for (int u: adj[now]) {
			if (low[u] == 0) {dfs(u);}
			low[now] = min(low[now], low[u]);
		}
		if (low[now] == num[now]) {
			scccount++;
			int v;
			do {
				v = st.top();
				scc[v] = scccount;
				num[v] = 100000000;
				low[v] = 100000000;
				st.pop();
			} while (v != now);
		}
	}

	int make_graph(int n, vector<pair<int, int>> edges, vector<pair<int, int>> &condensed_edges) {
		init_graph(n, edges);

		for (int i = 0; i < n; i++) {
			if (num[i] == 0) dfs(i);
		}

		set<pair<int, int>> ce;
		for (auto [x, y]: edges) {
			if (scc[x] != scc[y]) ce.insert({scc[x], scc[y]});
		}
		for (auto [x, y]: ce) {
			condensed_edges.emplace_back(x, y);
		}
		return scccount+1;
	}
} cgm;

vector<int> adj[10];
bitset<10> vis;
vector<int> topo;

void dfs(int now) {
	vis[now] = 1;
	for (int u: adj[now]) {
		if (!vis[u]) dfs(u);
	}
	topo.push_back(now);
}

char ans[21][21][4000];

void solve(int n) {
	vector<pair<int, int>> edges;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x; cin >> x;
			if (x) edges.emplace_back(i, j);
		}
	}

	vector<pair<int, int>> condensed_edges;
	int sc = cgm.make_graph(n, edges, condensed_edges);
	for (auto [u, v]: condensed_edges) {
		adj[u].push_back(v);
	}

	for (int i = 0; i < sc; i++) {
		if (!vis[i]) dfs(i);
	}
	reverse(topo.begin(), topo.end());

	int x = sc*2 + 1, y = sc*2 + 1, z = sc*20;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < z; k++) {
				ans[i][j][k] = '.';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cerr << cgm.scc[i] << ' ';
	}
	cerr << '\n';
	for (int i: topo) cerr << i << ' ';
	cerr << '\n';

	for (int i = 1, j = 0, cnt = 20, petr = 0; i < x; i += 2, j += 2, cnt += 20, petr++) {
		if (petr >= topo.size()) break;
		for (int k = 0; k < cnt; k++) {
			ans[i][j][k] = '#';
		}
		int now = topo[petr];
		int pts = 0;
		for (int nd = 0; nd < n; nd++) {
			if (cgm.scc[nd] == now) {
				ans[i-1][j][pts] = '1' + nd;
				pts++;
			}
		}

		for (int u: adj[now]) {
			int id_u = 0;
			for (int id = 0; id < topo.size(); id++) {
				if (topo[id] == u) {
					id_u = id; break;
				}
			}

			int gs = cnt - 20 + id_u;
			int dif = (id_u - petr)*2 - 1;

			int s = j + 1;
			while (dif--) {
				ans[i][s][gs] = '#';
				s += 2;
			}
		}
	}

	assert(z*y*x <= 1000000);
	cout << z << ' ' << y << ' ' << x << '\n';
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < z; k++) {
				cout << ans[i][j][k];
			}
			cout << '\n';
		}
		cout << '\n';
	}
}

signed main()
{
	//ios_base::sync_with_stdio(false), cin.tie(NULL);

	int testcase = 1;
	//cin >> testcase;
	while (testcase--)
	{
		int n; cin >> n;
		//for (int i = 1; i <= 64; i++) 
		solve(n);
	}
	
}
