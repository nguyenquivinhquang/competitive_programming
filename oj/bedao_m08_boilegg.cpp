#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
using namespace std;
const int mxn = 1e6;
bool mark[mxn+5];
vector <int> prime;
void seive() {
    for(ll i = 2; i * i <= mxn; i++) {
        for(ll j = i * i; j <= mxn; j += i)
            mark[j] = 1;
    }
    for(ll i = 2; i <= mxn; i++)
        if(!mark[i])prime.pb(i);
}
ull mod_ad(ull a, ull b, ull mod) {
    return (((a%mod)+(b%mod))+mod)%mod;
}
ull mod_mul(ull a, ull b, ull mod) {
    ll x = ((a%mod)*(b%mod))%mod;
    return (x+mod)%mod;
}
ull mod_mul_big(ull a, ull b, ull mod) {
    ull x = 0, y = a%mod;
    while(b > 0) {
        if(b % 2ll == 1)
            x = mod_ad(x, y, mod);
        b >>= 1ll;
        y = mod_mul(y, 2ll, mod);
    }
    return x%mod;
}
ull bin_pow(ull a, ull b, ull mod) {
    ull res = 1;
    while(b > 0)
    {
        if(b % 2 == 1)res = mod_mul_big(res, a, mod);
        b >>= 1;
        a = mod_mul_big(a, a, mod);
    }
    return res%mod;
}
bool is_prime_farmet(ull n) {
    if(n <= 4)
        return n==2 || n == 3;
    for(ll i = 0; i < 5; i++)
    {
        ull a = 2ull + rand() % (n-3);
        ull res = bin_pow(a, n-1, n);
        if(res != 1)return false;
    }
    return true;
}
bool is_sqre_of_prime(ll n) {
    ll x = sqrt((double)n);
    ll y = ceil((double)sqrt((double)n));
    if(x == y && is_prime_farmet(x))return 1;
    return 0;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    seive();
    int testcase = 1;
    while (testcase--) {
        ll n;
        cin >> n;
        ll ans = 1;
        for(ll i = 0; prime[i] * prime[i] * prime[i] <= n && i < prime.size(); i++) {
            if(n % prime[i] == 0)
            {
                ll cnt = 1;
                while(n%prime[i] == 0)
                {
                    n/=prime[i];
                    cnt++;
                }
                ans *= cnt;
            }
        }
        if(n > 1) {
            if(is_prime_farmet(n))ans *= 2;
            else if(is_sqre_of_prime(n))ans *= 3;
            else ans *= 4;
        }
    
        cout << ans  << "\n";
    }
}