#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a , b) for (int i = a; i <(b); ++i)
typedef long long ll;
typedef vector<int> vi;

typedef bitset<100> bs;

int solveLinear(vector<bs>& A, vi &b, bs& x, int m) {
	int n = sz(A), rank = 0, br;
	assert(m <= sz(x));
	vi col(m); iota(all(col), 0);
	rep(i, 0, n) {
		for (br=i; br < n; ++br) if (A[br].any()) break;
		if (br == n) {
			rep(j, i, n) if (b[j]) return -1;
			break;
		}
		int bc = (int)A[br]._Find_next(i-1);
		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		rep(j, 0, n) if (A[j][i] != A[j][bc]) {
			A[j].flip(i); A[j].flip(bc);
		}
		rep(j, i+1, n) if (A[j][i]) {
			b[j] ^= b[i];
			A[j] ^= A[i];
		}
		rank++;
	}

	x = bs();
	for (int i = rank; i--;) {
		if (!b[i]) continue;
		x[col[i]] = 1;
		rep(j,0,i) b[j] ^= A[j][i];
	}
	return rank;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<bs> A(n);
	vi B(n, 1);
	bs ans;

	while (m--) {
		int u, v; cin >> u >> v; u--, v--;
		A[u][v] = A[v][u] = 1;
		A[u][u].flip(); A[v][v].flip();
	}

	if (solveLinear(A, B, ans, n) == -1) cout << "N\n";
	else {
		cout << "Y\n";
		/*for (int i = 0; i < n; i++) {
			cout << A[i] << ' ' << B[i] << '\n';
		}
		cout << '\n';
		for (int i = 0; i < n; i++) {
			cout << ans[i];
		}*/
	}

	return 0;
}