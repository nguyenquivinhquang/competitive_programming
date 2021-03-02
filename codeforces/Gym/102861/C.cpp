#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a , b) for (int i = a; i <(b); ++i)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

struct trie{
	struct Vertex{
		vector<int> nxt;
		int id;

		Vertex() {
			nxt.resize(26, -1);
			id = -1;
		}
	};

	int cnt = 1;
	vector<Vertex> v;

	void insert_string(string s, int xt) {
		if (v.empty()) v.push_back(Vertex());
		int cur = 0;
		for (char c: s) {
			int d = c - 'a';
			if (v[cur].nxt[d] == -1) {
				v.push_back(Vertex());
				v[cur].nxt[d] = cnt;
				cnt++;
			}
			cur = v[cur].nxt[d];
		}
		v[cur].id = xt;
	}

	int label(int i) {
		return v[i].id;
	}

	int get_nxt(int i, int c) {
		return v[i].nxt[c];
	}
};

const int MAXN = 100006;

int n, m;
int pA[MAXN], pB[MAXN];

void dfs(int now, int prev, trie &A, trie &B, int curB) {
     cout << now << endl;
	if (A.label(now) != -1 && prev != -1 && curB != -1 && B.label(curB) != -1) {
		pA[prev] = pA[A.label(now)] = 1;
	}
	if (A.label(now) != -1) {
		prev = A.label(now);
		curB = 0;
	}

	for (int i = 0; i < 26; i++) {
		if (A.get_nxt(now, i) == -1) continue;

		int nxtB = curB;
		if (curB != -1) nxtB = B.get_nxt(curB, i);

		dfs(A.get_nxt(now, i), prev, A, B, nxtB);
	}
}

void solve(trie A, trie B) {
	dfs(0, -1, A, B, 0);
	cout << endl;
}

trie A, B;

signed main() {
	//ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		A.insert_string(s, i);
	}
	for (int i = 1; i <= m; i++) {
		string s; cin >> s;
		B.insert_string(s, i);
	}
	solve(A, B);
	for (int i = 1; i <= max(n, m); i++) {
		swap(pA[i], pB[i]);
	}
	solve(B, A);
	for (int i = 1; i <= max(n, m); i++) {
		swap(pA[i], pB[i]);
	}

	int ans1 = n, ans2 = m;
	for (int i = 1; i <= n; i++) ans1 -= pA[i];
	for (int i = 1; i <= m; i++) ans2 -= pB[i];
	cout << ans1 << ' ' << ans2 << '\n';

	return 0;
}