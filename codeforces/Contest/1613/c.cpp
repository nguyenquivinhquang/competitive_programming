#include <bits/stdc++.h>
#define int long long
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, h;
int a[N];
bool check(int k) {
    int total = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i-1] + k < a[i]) total+=k;
        else total += a[i] - a[i-1];
    }
    total += k;
    return !(total < h);
}
void solve() {
    cin >> n >> h;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = 1e18+5, res = 1;
    while(l <= r) {
        int mid = (l+r)>>1;
        if (check(mid)) res = mid, r = mid-1;
        else l = mid+1;
    }
    cout << res << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
