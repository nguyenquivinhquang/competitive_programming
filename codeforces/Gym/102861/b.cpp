#include <bits/stdc++.h>
using namespace std;
const int N = 13;
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, fee[N][N];	
	int D, L, R, C;
	cin >> n;
	bool check = true;
	memset(fee, 0, sizeof(fee));
	for (int i = 1; i <= n; i++) {
		cin >> D >> L >> R >> C;
		int x = R, y = C;
		if (D == 0) y = C + L - 1; else x = R + L - 1;
		for (int i = R; i <= x; i++)
			for (int j = C; j <= y; j++) {
				if (i > 10 || j > 10) {
					cout <<"N";
					return 0;
				}
				fee[i][j]++;
				if (fee[i][j] > 1) check = false;
			}	

	}
	if (check == false) cout << "N"; else cout << "Y";
	
	return 0;
}