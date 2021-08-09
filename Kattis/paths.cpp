#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

int n, m, k;
int color[N], dp[N];
bool trace[N];
vector<int> vertice[N], order;
void dfs(int u, int cur_id) {
    if (cur_id == k &&  color[u] == order[cur_id - 1] ) dp[u] = 1;
    if (cur_id == k  || color[u] != order[cur_id - 1]) return;
    trace[u] = true;
    
    for (auto v : vertice[u]) {
        if (trace[v] == false) dfs(v, cur_id + 1);
        dp[u] += dp[v];
    }
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> color[i];
    for (int i = 1; i <= k; i++) order.push_back(i);
    for (int i = 1 ; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        vertice[x].push_back(y);
        vertice[y].push_back(x);
    }
    ll res = 0;
    cerr << "Begin------- " << endl;
    do {
         for (auto v : order) cerr << v << " ";
         cerr << endl;
         memset(dp, 0, sizeof(dp));
         memset(trace, false, sizeof(trace));
         for (int i = 1; i <= n; i++) {
            if (color[i] != order[0]) continue;
            dfs(i, 1);
            res += dp[i];
            cerr << i << " " << dp[i] << endl;
            
        }
    } while (next_permutation(order.begin(), order.end()));
    cout << res;
}
