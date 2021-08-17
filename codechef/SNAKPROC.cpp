#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

void solve() {
    int n;
    char a[N]; ll res = 0;
    cin >> n;
    for (int i = 1; i <= n;i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (a[i] == '.') continue;
        if (a[i] == 'H') res++;
        else res--;
        if (res < 0 || res > 1) {
            cout << "Invalid\n";
            return;
        }
    }
    if (res != 0) {
        cout << "Invalid\n";
        return;
    }
    cout << "Valid\n";

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) solve();

}
