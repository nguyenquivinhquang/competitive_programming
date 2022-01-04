#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 500009;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int a[N];
void solve() {
    int n, k; cin >> n >> k;
    int res = 0;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + k);
    reverse(a + 1, a + 1 + k);
    int cat = 0;
    for (int i =1 ; i <= k; i++) {
        if (a[i] <= cat) continue;
        cat += n - a[i];
        res++;
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
