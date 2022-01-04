#include <bits/stdc++.h>
#define int long long
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
map<int, int> l, r;
vector<pair<int, int>> e;
int n;
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        

        cin >> n;
        
        for (int i = 0 ; i < n ; i++) {
            int u, v;
            cin >> u >> v;
            e.push_back({u, v});
            l[u]++;
            r[v]++;
        }
        int res = n * (n-1) * (n- 2) / 6;
        for (auto [u, v] : e) {
            res -= (l[u]-1) * (r[v] - 1);
        }
        cout << res << "\n";
        l.clear(); r.clear(); e.clear();
    }
}
