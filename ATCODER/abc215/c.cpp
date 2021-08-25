#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1000;
string n; int k;
vector<string> res;
void solve() {
    cin >> n >> k;
    sort(n.begin(), n.end());
    do {
        res.push_back(n);
    } while (next_permutation(n.begin(), n.end()));
    sort(res.begin(), res.end());

    cout << res[k-1];
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int testcase = 1;
    while(testcase--) solve();
}
