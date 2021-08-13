#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, ll> pii;
typedef vector<int> vi;

struct SuffixArray {
	vi sa, lcp;
	SuffixArray(string& s, int lim=256) { // or basic_string<int>
		int n = sz(s) + 1, k = 0, a, b;
		vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		rep(i,1,n) rank[sa[i]] = i;
		for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};
ll k, n, distribution[1000000];

struct STLazy {
	int n;
	vector<ll> tr, lz;

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

		tr[v] = tr[2*v] +  tr[2*v+1];
	}

	ll query(int v, int lo, int hi, int l, int r) {
		push(v, lo, hi);
		if (lo > hi || lo > r || hi < l) return 0;

		if (lo >= l && hi <= r) return tr[v];

		int mid = (lo + hi)/2;
		ll p1 = query(v*2, lo, mid, l, r);
		ll p2 = query(v*2 + 1, mid+1, hi, l, r);
		
		return p1 + p2;
	}

	void update(int l, int r, int val) {
		update(1, 0, n-1, l, r, val);
	}

	int query(int l, int r) {
		return query(1, 0, n-1, l, r);
	}
};
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
	// freopen("input.txt", "r", stdin);
    string str;
    cin >> str;
    n = str.length();
    SuffixArray suf(str);
    STLazy lazy(n+1);
    vector<int> sa = suf.sa, lcp = suf.lcp;
    
    for (int i = 1; i <= n; i++) {
        ll le = n - sa[i];
        le -= lcp[i];
		lazy.update(lcp[i], lcp[i] + le-1, 1);
        

    }
    for (int i = 0; i < n; i++) cout << lazy.query(i,i) << " ";
}
