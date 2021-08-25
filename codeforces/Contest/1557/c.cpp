#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;
const int MOD = 1e9+7;
using namespace std;

long long modpow(long long n, long long k, long long MOD) {
	long long ans = 1; n %= MOD;
	while (k > 0) {
		if (k & 1) ans = (ans*n) % MOD;
		k >>= 1; n = (n*n) % MOD;
	}
	return ans; 
}
int n, k;
ll res = 0;
void solve() {
    cin >> n >> k;
    res = 0;
    for (int i = 1; i <= k; i++) {
        res += modpow(2, k-i, MOD);
    }
    if (k != 0) res += modpow(2,n-1,MOD)/2; else res += 1;
    cout << res << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
}   
