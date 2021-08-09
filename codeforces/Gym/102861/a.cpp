#include <bits/stdc++.h>
using namespace std;

#define int long long

double dp[1000001];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, a, b; cin >> n >> a >> b;
	double ex = 1;
	if (a == 0) {
		ex = 1.0*(b+1)/b;
		a = 1;
	}
	for (int i = 1; i <= n; i++) {
		double ans = 0;
		int l = max(0LL, i-b);
		int r = max(0LL, i-a);

		double gs = dp[r];
		if (l > 0) gs -= dp[l-1];
		gs /= b-a+1;
		dp[i] = gs + ex;

		dp[i] += dp[i-1];
	}
	cout << fixed << setprecision(12) << dp[n]-dp[n-1] << '\n';

	return 0;
}