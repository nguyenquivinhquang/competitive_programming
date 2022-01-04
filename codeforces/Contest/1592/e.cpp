#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000009;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int prefix[N], a[N], n;
ll get(int l, int r) {
    return prefix[r] - prefix[l-1];
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] ^ a[i];
    }
    map<int, int> trace;
    int res = 0;
    trace[a[1]] = 1;
    for (int i = 2; i <= n; i++) {
        map<int, int> temp;
        for (auto v : trace) {
            int val = v.first & a[i];
            if (val == 0) continue;
            temp[val] = v.second;
            int sum = get(v.second, i);
            if (sum < val) {
                res = max(res, (i - v.second + 1));
            }
        }
        trace = temp;

        if (trace.find(a[i]) == trace.end()) {
            trace[a[i]] = i;
        }
    }
    cout << res;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    // cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
