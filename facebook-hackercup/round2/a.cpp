#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;
int cond[N][N];
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
map<int,int> trace;
int n, m, res;
void solve() {
    vector<vector<int>> a, trace;
    vector<int> dp;
    res = 0; trace.clear();
    cin >> n >> m;
    a.resize(n + 5); trace.resize(n + 5);
    dp.resize(m + 10);
    a[0].resize(m + 3); trace[0].resize(m + 3);
    multiset<pii> pre, cur;
    for (int i = 1; i <= m; i++) {
        cin >> a[0][i];
        trace[0][i] = a[0][i];
        pre.insert({a[0][i], i});
    }
    sort(a[0].begin() + 1, a[0].begin() + 1 + m);
    
    queue<int> du;
    for (int i = 1; i <= n; i++) {
        a[i].resize(m + 3); trace[i].resize(m  + 3);
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            auto it = pre.lower_bound({a[i][j], -1});
            if (it == pre.end()) {
                du.push(a[i][j]);
                continue;
            }
            
            if (it->first != a[i][j]) {
                du.push(a[i][j]);
                continue;
            }
            trace[i][it->second] = a[i][j];
            pre.erase(it);
        }
        
        for (int j = 1; j <= m; j++) {
            if (trace[i][j] != 0) continue;
            trace[i][j] = du.front();
            du.pop();
        }
        pre.clear();
        for (int j = 1; j <= m; j++) {
            pre.insert({trace[i][j], j});
        }

    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (trace[i][j] != trace[i-1][j]) dp[j]++;
        }
    }
    int debt = 0;
    for (int i = 1; i <= m; i++) {
        res += max(0, dp[i] - 1);
        if (dp[i] - 1 < 0) debt++;
    }
    cout << res - min(m - debt,debt) <<  "\n";

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    freopen("/mnt/Code/competitive_programming/facebook-hackercup/round2/input.txt", "r", stdin);
    freopen("/mnt/Code/competitive_programming/facebook-hackercup/round2/output.txt", "w", stdout);
    int test; cin >> test;

    for (int t = 1; t <= test; t++) {
        cout << "Case " << "#" << t << ": "; solve();
    }
}
