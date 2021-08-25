#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
void solve() {
    int row, column;
    int n;
    cin >> n;
    ll t = sqrt(n); 
    if (t * t != n ) t++;
    ll square = t*t;
    if (n <= square - t + 1) {
        row = n - (t-1)*(t-1);
        column = t;
    } else {
        column = square - n + 1;
        row = t;
    }
    cout << row << " " << column << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}
