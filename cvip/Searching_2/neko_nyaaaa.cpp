//https://www.spoj.com/problems/EKO/en/
#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 2000009;
const double eps = 0.000001;
int a[N], n, k;
bool f(int m) {
    int diff = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > m) diff += a[i] - m;
    }
    return diff >= k;
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 +n);
    a[0] = 0;
    int l = 1, r = a[n], mid, res = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (f(mid)) {
            r = mid - 1;
            res = max(res, mid);
        }
        else l = mid + 1;
//        cout << l << " " << mid << " " << r << endl;

    }
    cout << res << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false);
    solve();
}
