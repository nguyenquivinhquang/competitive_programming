#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 4000;
const int Mod = 998244353;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, a[N], b[N];
int res[N][N], prefix[N];
struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif, s[pos] %= Mod;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1],res %= Mod;
		return res;
	}
};
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= n; j++) cin >> b[j];
    FT ft(N);
    for (int i = a[1]; i <= b[1]; i++) ft.update(i,1);
    for (int i = 2; i <= n; i++) {
        FT  temp(N);
        for (int j = a[i]; j <= b[i]; j++) {
            int sum = ft.query(j+1) - ft.query(a[i-1]);
            // int x = ft.query(j);
            temp.update(j, sum);
        }
        ft = temp;
    }
    cout << ft.query(b[n] + 1);
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1;
//    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
