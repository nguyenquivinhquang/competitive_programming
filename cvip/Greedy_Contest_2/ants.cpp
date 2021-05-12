//https://open.kattis.com/problems/ants
#include <bits/stdc++.h>
#define ll long long
#define pp pair<double, double>
using namespace std;
const int N = 1e6 + 2;
int L, n;
int a[N];
void solve() {
    int time_min = 0, time_max = 0;
    cin >> L >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        time_max = max(time_max, max(a[i], L - a[i]));
        time_min = max(time_min, min(a[i], L - a[i]));

    }

    cout << time_min << " " << time_max << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        solve();
    }
}
