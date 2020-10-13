#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;

signed main()
{
	fastio;
	int testcase; cin >> testcase;
	while (testcase--) {
		int n; cin >> n;
		long long ans = 1LL*n*(n-1)/2;
		
		int xa[n], ya[n], xb[n], yb[n];
		for (int i = 0; i < n; i++) {
			cin >> xa[i] >> ya[i] >> xb[i] >> yb[i];
		}

		// exclude parallel pairs
		map<pair<int, int>, vector<int>> cnt;
		vector<int> x0, y0;
		for (int i = 0; i < n; i++) {
			int x = xa[i] - xb[i];
			int y = ya[i] - yb[i];

			int g = __gcd(x, y);
			x /= g; y /= g;

			if (x == 0) {
				x0.push_back(xa[i]);
			} else if (y == 0) {
				y0.push_back(ya[i]);
			} else {
				if (y < 0) x *= -1, y *= -1;
				int c = x*xa[i] - y*ya[i];
				cnt[{x, y}].push_back(c);
			}
		}

		long long x0s = x0.size(), y0s = y0.size();
		ans -= x0s*(x0s - 1)/2;
		ans -= y0s*(y0s - 1)/2;

		map<int, int> c2;
		for (int i: x0) {
			ans += c2[i];
			c2[i]++;
		}
		c2.clear();
		for (int i: y0) {
			ans += c2[i];
			c2[i]++;
		}

		for (auto [p, v]: cnt) {
			long long vs = v.size();
			ans -= vs*(vs-1)/2;

			c2.clear();
			for (int i: v) {
				ans += c2[i];
				c2[i]++;
			}
		}

		cout << ans << '\n';

		// include same pairs

	}
}