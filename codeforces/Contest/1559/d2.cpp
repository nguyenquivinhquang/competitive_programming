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
	vi e, trace;
	UF(int n) {
        for (int i = 0; i <= n; i++) e.push_back(i);
	}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) {
	    if (x == e[x]) return x;
	 return e[x] = find(e[x]); }
	bool check(int a, int b) {
        a = find(a), b = find(b);
		if (a == b) return false;
		return true;
	}
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (a > b) swap(a, b);
		e[b] = a;
		return true;
	}


};
void solve() {
    int res = 0,x,y;
    cin >> n >> m1 >> m2;
    UF a(n+2), b(n+2);
    vector<pii> e;
    for (int i = 1; i <= m1; i++) {
        cin >> x >> y;
        a.join(x, y);
    }
    for (int i = 1; i <= m2; i++) {
        cin >> x >> y;
        b.join(x, y);
    }

    vector<int> cc1, cc2;
    for (int i = 2; i <= n; i++) {
        if (a.check(1,i) && b.check(1,i)) {
            a.join(1,i); b.join(1,i);
            e.push_back({1,i});
            continue;
        }
        if (a.find(i) != 1) cc1.push_back(i);
        if (b.find(i) != 1) cc2.push_back(i);
    }
//    for (auto v : cc1) cout << v << " ";
//    cout << endl;
    while (cc1.size() && cc2.size()) {
        if (a.find(cc1.back()) == 1 && b.find(cc1.back()) == 1) {
            cc1.pop_back(); continue;
        }
        if (a.find(cc2.back()) == 1 && b.find(cc2.back()) == 1) {
            cc2.pop_back();  continue;
        }

        e.push_back({cc1.back(), cc2.back()});
        a.join(cc1.back(), cc2.back());
        b.join(cc1.back(), cc2.back());
//        continue;

    }


    cout << e.size() << "\n";
    for (auto v : e) {
        cout << v.first << " " << v.second << "\n";
    }

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1;
    while (testcase--) solve();
}
