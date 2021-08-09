#include<bits/stdc++.h>
#define int long long
#define pp pair<int, int>

using namespace std;
int a,b, c1, c2, k;
pp points[7];
int check_cut(int a, int b, int c) {
    int pos = 0, neg = 0;
    for (int i = 1; i <= k; i++) {
        int t = a * points[i].first + b * points[i].second - c;
        if (t == 0) continue;
        if (t > 0) pos = 1; else neg = 1;

    }
    if (pos != 0 && neg != 0) return 0;
    return pos - neg;
}
void solve() {
    cin >> a >> b >> c1 >> c2;
    cin >> k;
    for (int i = 1; i <= k; i++)
        cin >> points[i].first >> points[i].second;
    int check1 = check_cut(a, b, c1), check2 = check_cut(a, b, c2);
    if (check1 == 0 || check2 == 0)
        cout << "YES \n";
    else if (check1 != check2) cout << "Yes \n";
    else cout << "NO \n";

}
signed main() {
    int testcase;
    cin >> testcase;
    while (testcase--) {
        solve();

    }
}
