#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

void solve() {
    int n, odd, temp, even;
    vector<int> a;
    odd = even = 0;
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> temp;
        if (temp % 2 == 0) odd++;
        else even++;
    }
    if (odd == even) cout << "Yes \n";
    else cout << "No \n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int  testcase;
    cin >> testcase;
    while (testcase --) {
        solve();
    }
}
