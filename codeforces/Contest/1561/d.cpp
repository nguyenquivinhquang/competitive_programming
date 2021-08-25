#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int MOD, n;
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

		tr[v] = (tr[2*v] + tr[2*v+1]) % MOD;
	}

	int query(int v, int lo, int hi, int l, int r) {
		push(v, lo, hi);
		if (lo > hi || lo > r || hi < l) return 0;

		if (lo >= l && hi <= r) return tr[v];

		int mid = (lo + hi)/2;
		int p1 = query(v*2, lo, mid, l, r);
		int p2 = query(v*2 + 1, mid+1, hi, l, r);
		
		return (p1 + p2) % MOD;
	}

	void update(int l, int r, int val) {
		update(1, 0, n-1, l, r, val);
	}

	int query(int l, int r) {
		return query(1, 0, n-1, l, r);
	}
};
int find_pos(int x, int k) {
    int l = 1, r = x;
    while (l < r) {
        int mid = (l + r) / 2;
        int val = x / mid;
        if (val > k) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    // cin >> n >> MOD;
    cout << find_pos(5, 3);
}