#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1000;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAX_PR = 5000000;
bitset<MAX_PR> isprime;
vi eratosthenesSieve(int lim) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	rep(i,2,lim) if (isprime[i]) pr.push_back(i);
	return pr;
}
int x, step = 0;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    vi prime = eratosthenesSieve(5000000);
    cin >> x;
    // cout << prime[prime.size()-1];
    // return 0;
    while (x >= 4) {
        step++;
        for (auto v : prime) {
            int t = x - v;
            if ((t - v) % 2 == 0  && isprime[t] == 1 && (t -v) < x) {
                x = t - v;
                break;
            }
        }
    }
    cout << step;
}
