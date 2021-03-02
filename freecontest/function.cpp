#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll n, odd, even;

signed main() {
    cin >> n;
    if (n % 2 == 0) {
        ll si = (n + 1) / 2;
        even = si * (2 + n) / 2;
        n--;
        si = (n + 1) / 2;
        odd = si * (1 + n) / 2;
    } else {
        ll si = (n + 1) / 2;
        odd = si * (1 + n) / 2;
        n--;
        si = (n + 1) / 2;
        even = si * (2 + n) / 2;
    }
    cout << -odd + even;
}
