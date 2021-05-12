//uva-10385

#include <bits/stdc++.h>
#define ll long long
#define pp pair<double, double>
using namespace std;

const int N = 10001;
const double eps = 0.000001;
const double golden_const = (sqrt(5) - 1) / 2;
int n, x_res;
pp a[N];
double total_distance = 0;
double f(double x) {
    double diff = -1;
    double cheat_time = x / a[n].first + (total_distance - x) / a[n].second;
    for (int i = 1; i < n; i++) {
        double time = x / a[i].first + (total_distance - x) / a[i].second;
        diff = max(diff, time - cheat_time);
    }
    return diff;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    double l = 0, r = total_distance;
    while (r - l > eps) {
       double d = (r - l) * golden_const;
       double x = l + d, y = r -d;
       if (f(x) > f(y)) r = y; else l = x;
//       cout << l << " " << r << endl;
    }
    double res = l;
    if (f(res) < 0) cout << "The cheater cannot win.\n";
    else cout << "The cheater can win by " << int(round(f(res)*3600.0)) << fixed<< setprecision(2) <<" seconds with r = " << res << "km and k = " << total_distance - res << "km.\n";
}
signed main() {
    ios_base::sync_with_stdio(false);
    while (cin >> total_distance) {
        solve();

    }
}
