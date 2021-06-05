//https://www.spoj.com/problems/MAKETREE/
#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 100009;

using namespace std;
int n; // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;
int res[N];
void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int k, x, w;
    
    cin >> n >> k;
    adj.resize(n);
    for (int i = 1; i <= k; i++) {
        cin >> w;
        while (w--) {
            cin >> x;
            adj[x - 1].push_back(i - 1);
        }
    }
    topological_sort();
    ans.push_back(-1);
    for (int i = 0; i < ans.size() - 1; i++) {
        
        res[ans[i] + 1] = ans[i + 1] + 1;
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << "\n";
    }
}   
