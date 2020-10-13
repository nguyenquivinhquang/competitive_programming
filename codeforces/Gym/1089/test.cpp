#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int xr = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (i % 2) xr ^= x;
        }
        if (xr) cout << "first\n";
        else cout << "secoond\n";
    }

    return 0;
}