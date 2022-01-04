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
int n, k, friends[N], child[N];
bool visited[N];
void solve() {
    queue<pii> q; // {u, vlad = 0, friends = 1}
    cin >> n >> k;
    for (int i = 1; i <= k; i++){
        cin >> friends[i];
        visited[friends[i]] = true;
        q.push({friends[i], 1});
    }
    q.push({1, 0});
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        vertice[u].push_back(v);
        vertice[v].push_back(u);
        child[u]++; child[v]++;
    }
    bool check = false;

    visited[1] = true;
    while (q.size()) {
        int u = q.front().first, who = q.front().second;
        q.pop();
        for (auto v : vertice[u]) {
            if (visited[v] == true) continue;
            if (who == 0 && child[v] == 1) {
                check = true;
                break;
            }
            visited[v] = true;
            q.push({v, who});
 
        }
        if (check) break;
    }
    if (check) cout << "YES\n";
    else cout << "NO\n";
    for (int i = 1; i <= n; i++) {
        vertice[i].clear();
        visited[i] = false;
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