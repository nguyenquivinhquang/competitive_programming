#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, m, q; 
    cin >> n >> m >> q;

    long long x[n] = {0}, y[m] = {0};
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int r, v; cin >> r >> v;
            x[r-1] += v;
        } else if (t == 2) {
            int c, v; cin >> c >> v;
            y[c-1] += v;
        } else {
            int x1, y1, x2, y2; 
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, y1--;
            long long ax = 0, ay = 0;
            for (int i = x1; i < x2; i++) {
                ax = max(ax, x[i]);
            }
            for (int i = y1; i < y2; i++) {
                ay = max(ay, y[i]);
            }
            cout << ax+ay << '\n';
        }
    }
}