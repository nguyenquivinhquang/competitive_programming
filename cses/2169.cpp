#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define  N 210000
struct Fenwick {
	vector<ll> s;
	Fenwick(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

bool cmp(pair<pii,int> x, pair<pii,int> y) {
    if (x.first.first == y.first.first) return x.first.second > y.first.second;
    return x.first.first < y.first.first;
}

vector<pair<pii,int>> segment;
int n, res_1[N], res_2[N];
set<int> l;
map<int,int> compress;
int max_l = 0;
Fenwick id(N-1);
void _compress() {
    int c = 0;
    for (auto v : l) {
        c++;
        compress[v] = c;
    }
    compress[max_l] = ++c;
}
void erase(int x) {
    int val = compress[x];
    id.update(val, -1);
}
void update(int x) {
    id.update(compress[x], 1);
}
int get_position(int x, int i = 1) {
    if (i == 1)
    return id.query(compress[x] + 1);
    return  id.query(compress[x]);
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n; 
    for (int i = 1; i <= n; i++) {
        int x,y;
        cin >> x >> y;
        segment.push_back({{x, y}, i});
        l.insert(y);
        max_l = max(max_l, y);
    }
    max_l++;
    _compress();
    for (auto seg: segment) {
        update(seg.first.second);
    }
    sort(segment.begin(), segment.end(), cmp);
    for (auto seg: segment) {
        int ri = seg.first.second;
        erase(ri);
        res_1[seg.second] = get_position(ri);
    }
    for (int i = 1; i <= n; i++) cout << res_1[i] << " ";
    for (auto seg: segment) {
        int ri = seg.first.second;
        res_2[seg.second] = get_position(max_l) - get_position(ri, 0);
        update(ri);
    }
    cout << "\n";
    for (int i = 1; i <= n; i++) cout << res_2[i] << " ";
 }
