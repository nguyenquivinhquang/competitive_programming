#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void solve() {
    int n, m, k, sum = 0, res = -2;
    queue<int> trace;
    vector<int> a;
    cin >> n >> m >> k; a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (auto v : a) {
        sum += v;
        trace.push(v);
        while (abs(v - trace.front() ) > k || trace.size() > m ) {
            sum -=trace.front();
            trace.pop();
        }
        if (trace.size() == m) res = max(res, sum);
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
