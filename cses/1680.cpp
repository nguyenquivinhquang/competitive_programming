#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 100009;

using namespace std;

int n, m;
vector<int> edge[N];
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;
int nxt[N], dp[N];
bool isPossibel = false;
int dfs(int u) {
    if (u == n) return dp[n] = 1;
    if (dp[u] != -1) return dp[u];
    dp[u] = -1;
    for (auto v : edge[u]) {
        dfs(v);
        if (dp[v] + 1 > dp[u] && dp[v] != 0) {
            dp[u] = dp[v] + 1;
            nxt[u] = v;
        }
    }
    return dp[u];
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    memset(dp, -1, sizeof(dp));
    int x, y;
    cin >> n >> m;
    adj.resize(n+1);
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
    }
    dfs(1);
    cerr << "ok" << endl;
    if (dp[n] == -1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<int> ans; ans.push_back(1);
    int u = 1;
    while (u != n) {
        u = nxt[u];
        ans.push_back(u);
    }
    cout << ans.size() << "\n";
    for (auto v : ans) cout << v << " ";
}
/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/
