#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1009;

using namespace std;
int dp[N][4];
map<char,int> id;
void solve() {
    int x, y;
    string s;
    for (int i = 0; i < N; i++)
        dp[i][0] = dp[i][1] = 1e8;
    // dp[0][0] = dp[0][1] = 0;
    id['C'] = 0, id['J'] = 1;
    cin >> x >> y >> s;
    if (s[0] != '?')
        dp[0][id[s[0]]] = 0;
    else dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == '?') {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + y);
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + x);
        } else {
            if (s[i] == 'C')  dp[i][0] = min(dp[i - 1][1] + y, dp[i - 1][0]);
            if (s[i] == 'J') dp[i][1] = min(dp[i - 1][0] + x, dp[i - 1][1]);
        }
    }
    cout << min(dp[s.length() - 1][0], dp[s.length() - 1][1]) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    for (int i = 1 ; i <= testcase; i++) {
        cout << "Case #" << i <<": ";
        solve();
    }
}