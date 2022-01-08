#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
double x, y, d, p, res = 1e18, k;
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin >> k >> p >> x;
	for (int i = 1; i <= 10000; i++) {
        d = k / i;
        res = min(res, x * i + d * p);
	}
	cout << fixed << setprecision(3) << res << "\n";
}
