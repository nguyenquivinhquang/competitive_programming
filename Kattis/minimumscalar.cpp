#include <bits/stdc++.h>
using namespace std;

int n, m;
void solve() {
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    long long res = 0;
    for (int i = 0; i < n; i++) 
        res += a[i] * b[i];
    cout << res << "\n";
}
signed main() {
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        cout << "Case #" << t <<": ";
        solve();
    }
}