#include <bits/stdc++.h>
using namespace std;

#define int long long

int ggcd[100][100];

void init() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (i == 0 && j == 0) ggcd[i][j] = 0;
			else ggcd[i][j] = __gcd(i, j);
		}
	}
}

int choose3(int n) {
	return n*(n-1)*(n-2)/6;
}

int pos[100][100];
int neg[100][100];

void normalize(int &x, int &y) {
	int g = ggcd[abs(x)][abs(y)];
	x /= g; y /= g;

	if (x < 0) {
		x *= -1; y *= -1;
	} else if (x == 0 && y < 0) {
		y *= -1;
	}
}

void solve() {
	int n, m; cin >> n >> m;
	int ans = choose3(n*m);
	int surplus = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// pick(i, j) as center
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < m; y++) {
					int dx = x - i;
					int dy = y - j;

					if (dx == 0 || dy == 0) continue;

					normalize(dx, dy);
					if (dx < 0) {
						dx *= -1;
						surplus += neg[dx][dy];
						neg[dx][dy]++;
					} else {
						surplus += pos[dx][dy];
						pos[dx][dy]++;
					}
				}
			}

			for (int x = 0; x < n; x++) {
				for (int y = 0; y < m; y++) {
					int dx = x - i;
					int dy = y - j;

					if (dx == 0 || dy == 0) continue;
					normalize(dx, dy);
					if (dx < 0) {
						neg[-dx][dy] = 0;
					} else {
						pos[dx][dy] = 0;
					}
				}
			}
		}
	}
	surplus /= 3;
	surplus += choose3(n)*m + choose3(m)*n;

	cout << ans - surplus << '\n';
}

signed main() {
	freopen("input.txt","r",stdin);
    freopen("tung_out.txt","w", stdout);

    ios::sync_with_stdio(0); cin.tie(0);
	init();
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}