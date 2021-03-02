#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>
#define int long long
const int N = 1000;
const int Mod = 1e9 + 7;
using namespace std;
ll prex[1000000], prey[1000001];
ll fastPow(int x, int n) {
    if ( n < 0) return 0;
    if (n == 0) return 1;
    if (n == 1) return x;
    ll t = (fastPow(x, n /2));
    t = (t * t) % Mod;
    if (n % 2 != 0)
        t = (t * x) % Mod;
    return t;

}
signed main() {
    freopen("SUM.INP","r", stdin);
    freopen("SUM.OUT","w", stdout);
    ios_base::sync_with_stdio(NULL), cin.tie(NULL);
    int testcase;
    cin >> testcase;


    while (testcase--) {
        int i1, i2,j1, j2;
        cin >> i1 >> i2 >> j1 >> j2;
        ll x = (fastPow(2, i2 + 1) - fastPow(2, i1) + Mod ) % Mod ;
//        cout << x << endl;
        ll y = (fastPow(3, j2 + 1) - fastPow(3, j1) + Mod) % Mod * fastPow(2, Mod - 2) % Mod;
        cout << (x * y) % Mod << "\n";
    }


}
