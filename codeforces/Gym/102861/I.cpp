#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a , b) for (int i = a; i <(b); ++i)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define int long long 

int modpow(int n, int k, int M) {
	int ans = 1; n %= M;
	assert(n > 0);
	while (k) {
		if (k & 1) ans = (ans*n) % M;
		n = (n*n) % M; k /= 2;
	}
	return ans;
}

const int M = 1e9+7;
const int MAXN = 100005;

int n;
vector<int> adj[MAXN];
int ans[MAXN][2];
// state 0: don't ask itself, enough queries
// state 1: ask not enough queries (-1)

void dfs(int now) {
	if (adj[now].empty()) {
		ans[now][1] = 1;
	} else {
		for (int u: adj[now]) {
			dfs(u);
		}

		vector<int> sum, s2;
		for (int u: adj[now]) {
			sum.push_back(ans[u][0] + ans[u][1]);
			s2.push_back(ans[u][1]);
		}

		vector<int> pref, suf;
		int cur = 1;
		for (int i: sum) {
			cur = (cur*i) % M;
			pref.push_back(cur);
		}
		reverse(sum.begin(), sum.end());
		cur = 1;
		for (int i: sum) {
			cur = (cur*i) % M;
			suf.push_back(cur);
		}
		reverse(sum.begin(), sum.end());
		reverse(suf.begin(), suf.end());

		// state 0: don't ask itself --> must ask enough from all queries
		int prod = 1;
		for (int u: adj[now]) {
			prod = prod*(ans[u][0] + ans[u][1]) % M;
		}
		ans[now][0] = prod;

		// state 1: ask itself --> enough from most subtrees except 1
		for (int i = 0; i < adj[now].size(); i++) {
			int pr = 1;
			if (i > 0) pr = pr*pref[i-1] % M;
			if (i+1 < adj[now].size()) pr = pr*suf[i+1] % M;

			pr = (pr*s2[i]) % M;
			ans[now][1] = (ans[now][1] + pr) % M;
		}

		/*
		for (int u: adj[now]) {
			prod = prod*modpow(ans[u][0] + ans[u][1], M-2, M) % M;
			ans[now][1] = (ans[now][1] + prod*ans[u][1]) % M;

			prod = prod*(ans[u][0] + ans[u][1]) % M;
		}
		*/
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 2; i <= n; i++) {
		int p; cin >> p;
		adj[p].push_back(i);
	}
	dfs(1);

	cout << (ans[1][0] + ans[1][1]) % M << '\n';

	return 0;
}