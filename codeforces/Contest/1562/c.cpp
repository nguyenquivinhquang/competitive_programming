#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;
string str;
void solve() {
    cin >> n;
    cin >> str; str = '$' + str;
    for (int i = 1; i <= n; i++) {
        if (str[i] == '1') continue;
        if (i <= n/2) {
            cout << i << " " << n << " " << i + 1 << " " << n << "\n";
        } else {
            cout << 1 << " " << i << " " << 1 <<" "<<  i - 1 << "\n";
        }
        return;
    }
    cout << 1 << " " << n -1 << " " << 2 << " " << n << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    while (testcase--) solve();
}
