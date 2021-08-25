//https://codeforces.com/gym/100975F simple calculation
#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

ll fast_pow(ll x, ll n, ll modulo) {
    ll a, b;
    if (n==0) return 1;
    if (n == 1)
        return x % modulo;
    if (n % 2 == 0) {
        a = fast_pow(x, n / 2, modulo) % modulo;
        a = (a * a) % modulo;
        return a;
    }
    else {
        a = fast_pow(x, n / 2, modulo) % modulo;
        a = (a * a) % modulo;
        a = (a * x) % modulo;
        return a;
    }
}
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
ll cal(int x, int n, int modulo) {
    ll p = phi(modulo);
    return fast_pow(x, p + n % p, modulo);
}
void solve1(int n, int mod) {
    ll p = phi(mod);
    ll up = p + fast_pow(2, n, p);
    // cout << up << endl;
    cout << (fast_pow(2 , up, mod) + 1) % mod;
}
void solve2(int n, int mod) {
    ll up = pow(2, n);
    cout << (fast_pow(2, up, mod) + 1% mod);
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    freopen("calc.in", "r", stdin);
    freopen("calc.out", "w", stdout);
    ll n, mod; cin >> n >> mod;
    if (n > log2(mod)) solve1(n, mod);
    else solve2(n, mod);
}
