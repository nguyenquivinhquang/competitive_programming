#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


const int MAX_PR = 50000000;
bitset<MAX_PR> isprime;
set<int> eratosthenesSieve(int lim) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	set<int> pr;
	rep(i,2,lim) if (isprime[i]) pr.insert(i);
	return pr;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    set<int> prime = eratosthenesSieve(10000009);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n;
        cin >> n;
        if (n == 2 || n == 3) cout << "second\n";
        else cout << "first\n";
        
    }
}
