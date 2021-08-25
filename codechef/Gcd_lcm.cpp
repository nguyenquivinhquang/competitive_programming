#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;


signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    ll t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        ll gcd = __gcd(a, b);
        cout << gcd << ' ' << a * b / gcd << '\n';
    }
}
