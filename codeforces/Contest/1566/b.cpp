#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1000;
int  n;
string str;
void solve() {
    cin >> str;
    n = str.length();
    int find0 = 0;
    int l = -1, r = -1;
    int i = 0;
    for (auto v : str) {
        i++;
        if (v != '0') continue;
        find0++;
        if (l == -1) l = i;
        r = i;
    }
//    cout << r << " " << l << " ";
    if (!find0) cout << 0;
    else if (r - l  + 1 == find0) cout << 1;
    else cout << 2;

    cout << "\n";
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int testcase; cin >> testcase;
    while(testcase--) solve();
}
