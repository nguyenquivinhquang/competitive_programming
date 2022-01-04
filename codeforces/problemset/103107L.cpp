#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int N = 300009;
struct STLazy {
	int n;
	vector<int> tr, lz;
 
	STLazy(int n) : n(n), tr(4*n + 4), lz(tr) {}
 
	void push(int v, int lo, int hi) {
		if (lz[v] != 0) {
			tr[v] += lz[v];
			if(lo != hi) {
				lz[v*2] += lz[v];
				lz[v*2+1] += lz[v]; 
			}
			lz[v] = 0;
		}
	}
 
	void update(int v, int lo, int hi, int l, int r, int val) {
		push(v, lo, hi);
		if (lo > hi || lo > r || hi < l) return;
 
		if (lo >= l && hi <= r) {
			lz[v] += val; // put lazy tag here
			push(v, lo, hi);
			return;
		}
 
		int mid = (lo + hi) / 2;
		update(v*2, lo, mid, l, r, val);
		update(v*2 + 1, mid + 1, hi, l, r, val);
 
		tr[v] = max(tr[2*v], tr[2*v+1]);
	}
 
	int query(int v, int lo, int hi, int l, int r) {
		push(v, lo, hi);
		if (lo > hi || lo > r || hi < l) return -1e18;
 
		if (lo >= l && hi <= r) return tr[v];
 
		int mid = (lo + hi)/2;
		int p1 = query(v*2, lo, mid, l, r);
		int p2 = query(v*2 + 1, mid+1, hi, l, r);
		
		return max(p1, p2);
	}
 
	void update(int l, int r, int val) {
		update(1, 0, n-1, l, r, val);
	}
 
	int query(int l, int r) {
		return query(1, 0, n-1, l, r);
	}
};
bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
	auto [h1, d1, i1] = a;
	auto [h2, d2, i2] = b;
	if (d1*d2 <= 0) return d1 > d2;
	if (d1 > 0) return h1 < h2;
	return h1 - d2 > h2 - d1;
}
int query[N], inf = LLONG_MAX / 100000ll;
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
 
	int n; cin >> n;
	vector<int> h(n), d(n), res;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		d[i] = y-x;
	}
 
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int x, y, z; cin >> x >> y >> z;
		h.push_back(x);
		d.push_back(z-y);
	}
 
	vector<tuple<int, int, int>> lvs;
	for (int i = 0; i < n; i++) {
		lvs.emplace_back(h[i], d[i], i);
	}
	for (int i = 0; i < q; i++) {
		lvs.emplace_back(h[i+n], d[i+n], i+n);
	}
	STLazy tree(n + 1 + q);
	sort(lvs.begin(), lvs.end(), cmp);
	int i = 0,j = 0;
 
	for (auto [x, dis, index] : lvs) {
		if (index >= n) query[index] = i;
		i++;
	}
	int curPower = 0, init = 0;
	tree.update(0, n + q, -inf);
	for (int i = 0; i < n+q; i++) {
		auto [h, update, index] =  lvs[i];
		if (index >=n ) continue;
		tree.update(i, i, h + inf);
		tree.update(i + 1, n + q, -update);
	}
	res.push_back(tree.query(0, n + q));
 
	for (int i = n ; i  < n + q; i++) {
		auto [h, update, _] =  lvs[query[i]];
		int cur = query[i];
		// int pre = -1, nxt = -1, pre_h = 0, nxt_h = -1, cur_h;
		// cur_h = tree.query(cur, cur);
		tree.update(cur, cur, h + inf);
		tree.update(cur + 1, n + q, -update);
		
		res.push_back(tree.query(0, n + q));
	}
	for (auto v : res) cout << v << "\n";
 
	return 0;
}