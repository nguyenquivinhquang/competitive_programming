
//https://vn.spoj.com/problems/PNUMBER/
#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll, ll>
using namespace std;
const int N = 1000;
vector<int> prime = {2, 3, 5, 7, 13, 17, 23, 29, 19};
ll pow(int a, int n, int m) {
    if (n == 1) return a % m;
    ll t = pow(a, n / 2, m);
    t = (t * t) % m;
    if (n % 2 == 0) return (t) % m;
    else return (t * a) % m;
}
pp factor(ll n) {
    ll s = 0;
    while ( n % 2 == 0) {
        n /= 2;
        s++;
    }
    return {s, n};
}
bool check(ll s, ll d, ll n, ll a) {
    if (n == a) return true;
    ll p = pow(a, d, n);
    if (p == 1) return true;

//    cout << p << " " << a << " " << d << " " << n << endl;;
    while (s > 0) {
        if (p == n - 1) return true;
        p = (p * p )  % n;
        s--;
    }
    return false;

}
bool miller(ll n) {
    if (n == 2) return true;
    if (n % 2 == 0 || n == 1) return false;
    pp d = factor(n - 1);

    bool isPrime = true;

    for (auto p : prime){
        isPrime = check(d.first, d.second, n, p);
        if (isPrime == false) return false;
    }
    return true;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
        if (miller(i)) cout << i << "\n";
}
