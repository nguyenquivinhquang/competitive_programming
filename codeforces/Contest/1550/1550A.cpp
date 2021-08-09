#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

void solve() {
    int n, start = 1, sum = 1, c= 1;
    cin >> n;

    while (sum < n) {
        start += 2;
        sum += start;
        c++;
    }
    cout << c << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin  >> testcase;
    while (testcase--) solve();
}
