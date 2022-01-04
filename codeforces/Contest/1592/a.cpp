#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
const int N = 10000;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int a[N];
int n, h;
void solve() {
    cin >> n >> h;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    reverse(a + 1, a + 1 + n);
    int b[10];
    b[0] = a[1], b[1] = a[2], b[2] = a[1], b[3] = a[2] ;
    int step = 0, i = 0;
    ll sum = b[0] + b[1] + b[2] + b[3];
    step = 4 * (h/sum);
    ll remain = h % sum;
    // if (step == 0) remain = h;
    while (remain > 0) {
        remain -= b[i];
        step ++;
        i = (i + 1) % 4;
    }
    cout << step << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}