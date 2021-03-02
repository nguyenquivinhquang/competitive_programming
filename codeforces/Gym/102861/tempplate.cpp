#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;

#define rep(i, a , b) for (int i = a; i <(b); ++i)
ull pollard(ull n) {
	auto f = [n] (ull x) {return modmul (x, x, n) + 1;};
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y ) x = ++i, y= f(x);
		if ((q == modmul(prd, max(x, y) - min (x, y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, x);
}
vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}
signed main() {


}