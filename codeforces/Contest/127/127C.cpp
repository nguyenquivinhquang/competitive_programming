#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1000;
double t1, t2, x1, x2, t0;
double temperature (double y1, double y2) {
    return (y1 * t1 + y2 * t2 ) / (y1 + y2);
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin.exceptions(cin.failbit);
    double res = 100000000000000000; ll y1 = 0, y2 = 0;
    cin >> t1 >> t2 >> x1 >> x2 >> t0;
    if (t1 == t2) {
        cout << ll (x1) << " " << ll(x2);
        return 0;
    }
    for (int i = 0; i <= x1; i++) {
        double y_1 = i;
        int l = 0, r = x2, mid;
        if (i == 0) {
            mid = x2;
        } else
        while (l <= r) {

            mid = (l + r) >> 1;
            if (temperature(y_1, mid) >= t0) r = mid - 1;
            else l = mid + 1;

        }

        double T =  temperature(y_1, mid);
        if (T < t0)  T =  temperature(y_1, ++mid);
        if (T - t0 < 0 || mid > x2) continue;
        if (T - res < 1e-19 ) {

            if (T < res) res = T, y1 = y_1, y2 = mid;
            else  if (y_1 + mid > y1 + y2) y1 = y_1, y2 = mid;
        }
    }
    cout << y1 << " " << y2;
}

