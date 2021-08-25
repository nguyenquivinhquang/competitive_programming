#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 100009;
int n, m, dp[N], a[N];
bool trace[N];
const int MAX_PR = 5000000;
bitset<MAX_PR> isprime;
vector<int> prime;
void eratosthenesSieve(int lim) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	rep(i,2,lim) if (isprime[i]) prime.push_back(i);
	return ;
}
void pre_pro(int x ) {
     if (isprime[x]) {
       
        trace[x] = true;
        return ;
    }
    for (auto v : prime) {
        if (x < v) break;
        if (x % v != 0) continue;
        trace[v] = true;
        while (x % v == 0) x/=v;
     }
}
bool check(int x) {
    bool check = true;
    if (trace[x]) return false;
    for (auto v : prime) {
        if (x < v) break;
        if (x % v != 0) continue;
        if (trace[v] == true) return false;
        while (x % v == 0) x/=v;
     }
     return true;
}
void solve() {
    eratosthenesSieve(1e6);
    cin >> n >> m;
    vector<int> res;
    for (int i = 1; i <= n; i++) cin >> a[i], pre_pro(a[i]);
    for (int i = 1; i <= m; i++) if (check(i) == true) res.push_back(i);
    cout << res.size() << "\n";
    for (auto v : res) cout <<v << "\n";

}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    int testcase = 1;
    while(testcase--) solve();
}
