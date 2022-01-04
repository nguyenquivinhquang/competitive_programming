#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll a, b, c,d, x, p;
void solve() {
    cin >> a >> b >> c >> d;
    if ((a + b ) % p != (c + d) % p) {
        cout << "-1\n";
        return;
    }
    int step = 0;
    while (a <= c) {
        a = (2 * a) % p;
        b = (b + p -a ) % p;
        step++;
    }
    while (a > c) {
        a = (a + p - b) % p;
        b = (2 * b) % p;
        step++;

    }
    cout << a << " " << b << " " << p << endl;
     cout << "\n";

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> p >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
