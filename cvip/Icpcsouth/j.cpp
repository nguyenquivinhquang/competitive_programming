#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> P, S;
	DSU(int n) {
		P.resize(n+1);
		S.resize(n+1, 1);
		for (int i = 1; i <= n; i++) P[i] = i;
	}
	
	int find(int x) {
		if (x == P[x]) return x;
		return P[x] = find(P[x]);
	}
	
	bool merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return 0;
		if (S[a] < S[b]) swap(a, b);
		
		S[a] += S[b];
		P[b] = a;
		return 1;
	}
	
	int same(int a, int b) {
		return find(a) == find(b);
	}
};

const int MAXN = 4001;
    
int p[MAXN][MAXN];

signed main() {
    freopen("out.txt", "r", stdin);
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m; cin >> n >> m;
	vector<pair<int, int>> edge;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		edge.emplace_back(u, v);
	}

	DSU d(n);
	bitset<MAXN> used;
	while (1) {
		//cout << "Next ite\n";
		for (int i = 0; i < m; i++) {
			if (used[i]) continue;
			auto [u, v] = edge[i];

			int pu = d.find(u), pv = d.find(v); 
			//cout << i << ' ' << u << ' ' << v << ' ' << pu << ' ' << pv << endl;
			if (pu > pv) swap(pu, pv);
			p[pu][pv] = p[pv][pu] = 0;

			if (pu == pv) {
				cout << "No\n"; exit(0);
			}
		}

		bool cont = 0;
		for (int i = 0; i < m; i++) {
			if (used[i]) continue;

			auto [u, v] = edge[i];
			int pu = d.find(u), pv = d.find(v);
			if (pu > pv) swap(pu, pv);
			p[pu][pv]++; p[pv][pu]++;

			if (p[pu][pv] == 2) {
				//cout << "Found multiedge: " << i << endl;
				int s1 = i, s2 = -1;
				for (int j = 0; j < m; j++) {
					if (used[j]) continue;
					auto [U, V] = edge[j];

					int pU = d.find(U), pV = d.find(V);
					if (pU > pV) swap(pU, pV);

					if (pU == pu && pV == pv) {
						//cout << "Matching edge: " << j << endl;
						s2 = j; break;
					}
				}

				used[s1] = 1; used[s2] = 1;
				d.merge(u, v); //cout << "Merging " << u << ' ' << v << endl; 
				cont = 1; break;
			}
		}
		if (!cont) break;
	}
	cout << "Yes\n";

	return 0;
}
