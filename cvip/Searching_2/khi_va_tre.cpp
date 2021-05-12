//https://lightoj.com/problem/the-monkey-and-the-oiled-bamb

#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 100009;
const double eps = 0.000001;
int a[N], n;
bool f(int m) {
    for (int i = 1; i <= n; i++) {
        int diff = a[i] - a[i - 1];
        if (diff > m) return false;
        if (diff == m) m--;
    }
    return true;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 +n);
    a[0] = 0;
    int l = 1, r = 1e11, mid, res = 1e11;
    while (l <= r) {
        mid = (l + r) / 2;
        if (f(mid)) {
            r = mid - 1;
            res = min(res, mid);
        }
        else l = mid + 1;
//        cout << l << " " << mid << " " << r << endl;

    }
    cout << res << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false);
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        cout << "Case " << t <<": ";
        solve();
    }
}
