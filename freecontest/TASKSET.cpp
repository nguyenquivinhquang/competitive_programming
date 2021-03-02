#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;

    ll ans = 0;

    for (ll x = 1; x <= n; x *= 2) ans = max(ans, x);

    for (ll x = 3; x <= n; x *= 2) ans = max(ans, x);

    cout << n - ans;
}