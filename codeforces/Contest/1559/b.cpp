#include <bits/stdc++.h>
#define int ll 
#define ll long long
#define pp pair<int, int>

const int N = 1005;

using namespace std;
int a[N], n, b[N], dp[N][3]; // 0: R, 1: B
string s;
void solve() {
    cin >> n;
    cin >> s;
    int i = 0;
    for (i = 0; i < n; i++) {
        if (s[i] != '?') break;
    }
    if (i < n) {if (i % 2 == 1) {
        if (s[i] == 'R') s[0] = 'B';
        else s[0] = 'R';
    } else {
        s[0] = s[i];
    }}
    for (int i = 1; i < n; i++) {
        if (s[i] != '?') continue;
        if (s[i-1] == 'R') s[i] = 'B';
        else s[i] = 'R';
    }
    cout << s << "\n";


}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) solve();
}
