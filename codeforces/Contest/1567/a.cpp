#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void solve() {
    string str;
    int n;
    cin >> n >> str;
    for (auto v : str) {
        if (v == 'L' || v == 'R') cout << v;
        else if (v == 'U') cout <<'D';
        else cout << 'U';
    }
    cout << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
