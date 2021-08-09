#include <bits/stdc++.h>

#define ll long long
#define pp pair<double, double>

const int N = 1005;

using namespace std;
int n;
pp coor[N];
void solve() {
    // cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> coor[i].first >> coor[i].second;
    }
    coor[n + 1] = coor[1];
    double s = 0.0;
    for (int i = 1; i <= n; i++) {
        s += (coor[i].first + coor[i + 1].first) *
             (coor[i].second - coor[i + 1].second);
    }
    if (s < 0)
        cout << "CCW ";
    else
        cout << "CW ";

    s = abs(s) / 2.0;
    cout << fixed << setprecision(1);

    cout << s << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    while (cin >> n) {
        if (n == 0) return 0;
        solve();
    }
}