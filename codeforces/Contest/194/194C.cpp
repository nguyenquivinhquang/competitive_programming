#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph


bool IS_CUTPOINT[3000], visited[3000];
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                IS_CUTPOINT[v] = true;
            ++children;
        }
    }
    if(p == -1 && children > 1 )
       IS_CUTPOINT[v] = true;
}

void find_cutpoints() {
    timer = 0;
    
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}
char a[N][N];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    memset(IS_CUTPOINT, false, sizeof(IS_CUTPOINT));
    int u, v;
    cin >> u >> v;
    n = u * v;
    for (int i = 0; i < u; i++)
        for (int j = 0; j < v; j ++)
            cin >> a[i][j];
    adj.resize(n + 5);
    int total = 0;
    for (int i = 0; i < u; i++)
        for (int j = 0; j < v; j ++) {
            if (a[i][j] == '.') continue;
            if (a[i][j] == '#' && a[i + 1][j] == '#') {
                int x = i * v + j, y = (i + 1) * v + j;
                adj[x].push_back(y), adj[y].push_back(x);
                
            }
            if (a[i][j] == '#' && a[i][j + 1] == '#') {
                int x = i * v + j, y = (i) * v + j + 1;
                adj[x].push_back(y), adj[y].push_back(x);
                
            }
            if (a[i][j] == '#') total++;
        }
    if (total <= 2) {
        cout << -1;
        exit(0);
    }
    find_cutpoints();
    int total_cur = 0;
    for (int i = 0; i < n; i++)
        if (IS_CUTPOINT[i] == true) {
            total_cur++;
        }
    if (total_cur == 0) total_cur = 2; else total_cur = 1;
    cout << total_cur;
}

