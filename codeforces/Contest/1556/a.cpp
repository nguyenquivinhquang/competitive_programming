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
    int a, b;
    cin >> a >> b;
    if (a ==  b) {
        if (a == 0) cout << "0\n";
        else cout << "1\n";
        return;
    }
    if (abs(a - b) % 2 == 1) cout << -1;
    else cout << 2;
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
