#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
int a, b;
void solve() {
    int res = 1e9, c = 0;
    cin >> a >> b;
    while (1) {
        int total = 0, temp = a;
        if (b == 1) {
            c = 1;
            b++;
        }
        while (temp > 0) {
            temp /= b;
            total++;
        }
        if (total + c > res) break;
        res = min(res, total + c);
        b++;
        if (total == 1) break;
        c++;

    }
    cout << res << "\n";

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        solve();
    }

}
