#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;
int cond[N][N];
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
long long dp[N];
bool cmp(char cur, char pre) {
    if (pre == 'F' || cur == 'F') return true;
    return pre == cur;
}
void solve() {
    string str; char pre = '.';
    long long  res = 0, n, preF = -1;
    cin >> n >> str; 
    pre = str[0];
    for (int i = 1; i < str.length(); i++) {
        if (cmp(str[i], str[i-1])) {
            dp[i] = dp[i-1];
        } else {
            dp[i] = dp[i-1] * i + 1;
            dp[i] %= 1000000007;
        }
        res = (res + dp[i]) % 1000000007;
    }
    cout << res << "\n";

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int test; cin >> test;

    for (int t = 1; t <= test; t++) {
        cout << "Case " << "#" << t << ": "; solve();
    }
}
