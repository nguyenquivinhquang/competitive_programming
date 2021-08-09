#include <bits/stdc++.h>
using namespace std;

#define int long long

int dp[51][51][2];

int go(int b, int lf, bool eq, int lim) {
	if (b == -1) return (lf == 0);
	if (dp[b][lf][eq] != -1) return dp[b][lf][eq];

	int ans = 0;
	// insert 0
	// if lim bit = 1 --> not equal anymore
	// else, equality same
	if (lim & (1LL << b)) {
		ans += go(b-1, lf, 0, lim);
	} else {
		ans += go(b-1, lf, eq, lim);
	}

	// insert 1
	// if lim bit = 0, can insert iff not equal
	// else if lim bit = 1, equality same
	if (lf > 0) {
		if (lim & (1LL << b)) {
			ans += go(b-1, lf-1, eq, lim);
		} else {
			if (!eq) ans += go(b-1, lf-1, eq, lim);
		}
	}

	return dp[b][lf][eq] = ans;
}

int solve(int n, int k, int lim) {
	if (lim < 0) return 0;
	// how many with n bits, <= lim, has k bits
	memset(dp, -1, sizeof(dp));
	return go(n-1, k, 1, lim);
}

int n, k, a, b;
int w[50];

int get(int mx) {
	int ans = 0;
	for (int i = n-1; i >= 0; i--) {
		if (mx >= w[i]) {
			mx -= w[i];
			ans |= (1LL << i);
		}
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	cin >> a >> b;
	sort(w, w+n);

	int l = get(a-1);
	int r = get(b);

	cout << solve(n, k, r) - solve(n, k, l) << '\n';


	return 0;
}