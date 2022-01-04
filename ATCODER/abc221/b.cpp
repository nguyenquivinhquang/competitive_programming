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
    int n,p,res = 0;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        int temp; cin >> temp;
        if (temp < p) res++;
    }
    cout << res;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1;
//    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
