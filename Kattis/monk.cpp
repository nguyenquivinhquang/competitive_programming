//https://open.kattis.com/problems/monk
#include <bits/stdc++.h>
#define pp pair<double, double>

using namespace std;
const int N = 5005;
const double eps = 0.00000001;
int n, m;
pp a[N], b[N]; // first: dist, second: time

double asc(double t) {
    double distance = 0.0;
    for (int i = 1; i <= n; i++) {
        if (a[i].second < t) {
            distance += a[i].first;
            t -= a[i].second;
        } else {
            distance += (a[i].first / a[i].second) * t;
            return distance;
        }
    }
    return distance;
}
double desc(double t) {
    double distance = 0.0;
    for (int i = 1; i <= m; i++) {
        if (b[i].second < t) {
            distance += b[i].first;
            t -= b[i].second;
        } else {
            distance += (b[i].first / b[i].second) * t;
            return distance;
        }
    }
    return distance;
}
void solve() {
    double total_distance = 0, total_time = 0, t = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        total_distance += a[i].first;
        total_time += a[i].second;
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i].first >> b[i].second;
        t += b[i].second;
    }
    double l = 0, r = max(total_time, t), mid, res ;
    while (r - l > eps) {
        mid = (l + r) / 2.0;
        double dis_asc = asc(mid), dis_desc = total_distance - desc(mid);
//        cout << l << " " << mid << " " << r << " " << dis_asc << " " << dis_desc << endl;
        if (dis_asc < dis_desc) l = mid + eps;
        else r  = mid - eps, res = mid;
    }
    cout << res;
}
signed main() {
    ios_base::sync_with_stdio(false);
    solve();
}