#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
map<string, int> trace;
int n; string x,y;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        x = x + '&' + y;
        trace[x]++;
    }
    for (auto v : trace) {
        if (v.second > 1) {
            cout << "Yes";
            return;
        }
    }
    cout << "No";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int testcase = 1; 
    // cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}