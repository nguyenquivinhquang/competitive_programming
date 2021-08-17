#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define int long long
struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};
int n;
ll res = 0;
vector<pair<int,pii>> edge;
bool cmp(pair<int,pii> x, pair<int,pii> y) {
    return x.first  < y.first;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    int x,y, w;
    cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> x >> y >> w;
        x--, y--;
        edge.push_back({w, {x, y}});
    }
    sort(edge.begin(), edge.end(), cmp);
    UF tree(n);
    for (auto e: edge) {
        int w = e.first, u = e.second.second, v = e.second.first;
        res += w * tree.size(u) * tree.size(v);
        tree.join(u, v);
     }
    cout << res;
    return 0;
}
