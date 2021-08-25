#include <bits/stdc++.h>

#define ll  double
#define pp pair<int, int>

const int N = 300000;

using namespace std;
int a[N], n;
void solve() {
    cin >> n; ll sum =0;
    for (int i = 1; i <= n; i++){
        cin >> a[i]; 
        sum += a[i];
    } 
    sort(a + 1, a + 1 + n);
    
    // cout << sum << endl;
    ll prefix = 0;
    ll res = -1e12;
    for (int i = 1; i < n; i++) {
        prefix += a[i];
        ll surfix = sum - prefix;
        res = max(res, prefix / i + surfix / (n - i));
    }
    cout << res << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cout << fixed << setprecision(10);
    int t; cin >>  t;
    while (t--) {
        solve();
    }

}
