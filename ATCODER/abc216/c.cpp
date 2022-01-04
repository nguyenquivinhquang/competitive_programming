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
    vector<char> ans;
    ll n;
    cin >> n;
    while (n > 0) {
        if (n % 2 == 1) ans.push_back('A'), n--;
        else ans.push_back('B'), n/=2   ;
    
    }
    reverse(ans.begin(), ans.end());
    for (auto v : ans) cout << v;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    // cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
