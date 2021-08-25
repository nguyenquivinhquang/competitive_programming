#include <bits/stdc++.h>

const int N = 1005;

using namespace std;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int n, m1, m2;

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool check(int a, int b) {
        a = find(a), b = find(b);
		if (a == b) return false;
		return true;
	}
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};
void solve() {
    int res = 0,x,y;
    cin >> n >> m1 >> m2;
    UF a(n), b(n);
    vector<pii> e;
    for (int i = 1; i <= m1; i++) {
        cin >> x >> y;
        a.join(x, y);
    }
    for (int i = 1; i <= m2; i++) {
        cin >> x >> y;
        b.join(x, y);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
                if (a.check(i-1, j-1) == true && b.check(i-1, j-1) == true) {
                    a.join(i-1,j-1); b.join(i-1, j-1); res++;
                    e.push_back({i-1, j-1});
                }
        }
    }
    cout << res << "\n";
    for (auto v : e) {
        cout << v.first+1 << " " << v.second+1 << "\n";
    }

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1;
    while (testcase--) solve();
}
