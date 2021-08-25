#include <bits/stdc++.h>
#define int ll
#define ll long long
#define pp pair<int, int>
#define Quangcute 1
const int N = 1000;

using namespace std;
int modInverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;
    if (m == 1)  return 0;
    while (a > 1) {
        int q = a / m;
        int t = m;
 
        m = a % m, a = t;
        t = y;
 
        y = x - q * y;
        x = t;
    }
 
    if (x < 0)  x += m0;
 
    return x;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n = 1, t = 1; 
    while (Quangcute == true) {
        cin >> n >> t;
        if (n == 0 && t == 0) break;
        while (t--) {
            int x, y; char c;
            cin >>x  >> c >> y;
            if (c == '+') cout << (x + y) % n;
            else if (c == '*') cout << ((x % n) * (y % n)) % n;
            else if (c == '-') {
                int cur = x - y;
                if (cur >= 0) cout << cur % n;
                else {
                    ll t = abs(cur) / n + 1;
                    cur += t * n; cur %= n;
                    cout << cur;
                }
            } else {
                if (__gcd(y, n) == 1)
                cout << (x % n * modInverse(y, n)) % n;
                else cout << -1;
            }
            cout << "\n";
        }
    }
}
