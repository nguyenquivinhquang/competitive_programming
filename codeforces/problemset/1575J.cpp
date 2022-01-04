#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void solve() {

}
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m, k; cin >> n >> m >> k;
	int a[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
 
	while (k--) {
		int j, i = 0; 
        cin >> j; j--;
 
		while (i < n) {
			if (a[i][j] == 1) {
				a[i][j] = 2; j++;
			} else if (a[i][j] == 3) {
				a[i][j] = 2; j--;
			} else  i++;
			
		}
 
		cout << j+1 << ' ';
	}
 
	return 0;
}