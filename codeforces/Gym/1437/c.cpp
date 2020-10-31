#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 505;

using namespace std;
int temp, n, l, dp[N][N], t[N];
void solve(){
	cin >> n;
	l = 1;
	for (int i = 1; i <= n; i++)
		cin >> t[i];
	sort(t + 1, t + 1 +n);
	dp[1][0] = 1e9;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= 500; j++){
			dp[i][j] = min(dp[i-1][j-1] + abs(j - t[i]), dp[i][j - 1]);
			//cout << dp[i][j] << " ";
		}
		//cout << endl;
	}
	cout << dp[n][500] << "\n";	
	
}
signed main(){
	int testcase;
	cin >> testcase;
	for (int i = 1; i <= 500; i ++)
		dp[i][0] = 1e9;
	while(testcase -- ) {
	    solve();
	}

}


