//https://codeforces.com/contest/1359/problem/D

#include <bits/stdc++.h>
#define ll long long
#define INF 10987654321
const int N = 1000000;
using namespace std;
ll n, a[N], ans = 0;
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;

    for (ll i = 0; i < n; i++) cin >> a[i];

    for (ll x = 0; x <= 30; x++) {
        ll res = 0;
        for (ll i = 0; i < n; i++) {
            if (a[i] <= x)
                res += a[i];
            else
                res = 0;
            if (res < 0) res = 0;
            ans = max(ans, res - x);
        }
    }
    cout << ans;
}
