#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a , b) for (int i = a; i <(b); ++i)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


const int MAXN = 100005;

struct FT {
	vector <ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) {
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) {
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
} tr(MAXN);

int n, m, a[MAXN];
vector<int> adj[MAXN];

int sp[MAXN][19];

vector<pair<int, int>> que[MAXN];
int ans[MAXN];

void dfs(int now) {
	//cout << "Getting " << now << '\n';
	for (auto [u, v]: que[now]) {
		//cout << now << ' ' << u << ' ' << v << '\n';
		tr.update(u, 1);
		tr.update(v+1, -1);
	}
	ans[now] = tr.query(a[now] + 1);

	for (int u: adj[now]) dfs(u);

	for (auto [u, v]: que[now]) {
		tr.update(u, -1);
		tr.update(v+1, 1);
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> a[i] >> p;
		if (i != 1) {
			adj[p].push_back(i);
		}
		sp[i][0] = p;
	}
	for (int j = 1; j < 19; j++) {
		for (int i = 1; i <= n; i++) {
			sp[i][j] = sp[sp[i][j-1]][j-1];
		}
	}

	for (int i = 0; i < m; i++) {
		int o, l, r; cin >> o >> l >> r;
		for (int j = 18; j >= 0; j--) {
			if (a[sp[o][j]] >= l && a[sp[o][j]] <= r) o = sp[o][j];
		}
		//cout << "Owner " << i << ' ' << o << '\n';
		que[o].emplace_back(l, r);
	}

	dfs(1);

	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';

	return 0;
}