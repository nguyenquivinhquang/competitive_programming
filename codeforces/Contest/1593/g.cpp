#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int res(int x, int y, int z) {
    return max(0,  (max(y, z)) - x + 1);
}
void solve() {
    long long a,b,c; cin >> a >> b >> c;
    cout <<res(a,b,c) << " ";
    cout <<res(b,a,c) << " ";
    cout <<res(c,b,a) << " ";
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
