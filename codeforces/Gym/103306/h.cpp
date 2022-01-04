#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, m , MAX = 0;
int p[N], t[N];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    set<pii> s;
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < m; i++){
        cin >> t[i];
        MAX  = max(MAX, t[i]);
    }
    for (int i = 1; i <= n; i++) {
        s.insert({p[i], i});
    }
    for (int i = 0; i <= n; i++) {
        int cur_time = 0;
        while (cur_time < MAX) {
            auto it = s.lower_bound({cur_time - i, -1});
            
        } 
    }

}
