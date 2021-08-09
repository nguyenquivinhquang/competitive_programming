#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;
const int mod = 1000000007;

using namespace std;
ll lcm(ll x, ll y){
    return x * y / __gcd(x,y);
}
void solve() {
    ll n;
    cin >> n;
    ll temp = 1;
    ll ans = 0;
    ll k = 2;
    while (temp <= n) {
        ll lm = lcm(k, temp);
        ans += k * (n / temp - n / lm) % mod;
        ans %= mod;
        temp = lm;
        k++;
    }
    cout << ans << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int testcase;
    cin >> testcase;
    while (testcase--) {
        solve();
    }
}