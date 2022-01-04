#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
const int N = 200009;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vector<int> vertice[N];
int n, k, friends[N], child[N],  res = 0, father[N];
int visited[N];
void dfs(int u, int preU ) {
    for (auto v : vertice[u]) {
        if (v == preU) continue;
        father[v] = u;
        dfs(v, u);
    }
}
void solve() {
    queue<pii> q; // {u, vlad = 1, friends = 2 > k+1}
    cin >> n >> k;
    map<int,int> trace;
    for (int i = 1; i <= k; i++){
        cin >> friends[i];
        visited[friends[i]] = friends[i];
        q.push({friends[i], friends[i]});
        trace[friends[i]] = 1;
    }
    q.push({1, 1});
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        vertice[u].push_back(v);
        vertice[v].push_back(u);
        child[u]++; child[v]++;
    }
    bool check = false;
    trace[1] = 1;
    visited[1] = 1;
    dfs(1, 0);
    while (q.size()) {
        int u = q.front().first, who = q.front().second;
        q.pop();
        for (auto v : vertice[u]) {
            if (v != father[u] && who != 1) continue;
            if (visited[v] != 0){
                if (who != 1 && visited[v] != 1) {
                    trace[who] = 0;
                }
                continue;
            }
            if (who == 1 && child[v] == 1) {
                check = true;
                break;
            }
            
            visited[v] = who;
            q.push({v, who});
 
        }
        if (check) break;
    }
    trace[1] = 0;
    if (check) cout << "-1\n";
    else {
        int res = 0;
        for (auto v : trace) res += (v.second == 1);
        cout << res << "\n";
    }
    for (int i = 1; i <= n; i++) {
        vertice[i].clear();
        visited[i] = 0;
        child[i] = 0;
    }    
 
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}