#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pp pair<int, int>

const int N = 100009;

using namespace std;
int n;
vector<int> g1,g2;
vector<int> vertice[N];
void dfs(int u, int preU, int color) {
    if (color == 0) g1.push_back(u);
    else g2.push_back(u);
    for (auto v: vertice[u]) {
        if (v == preU) continue;
        dfs(v, u, (color + 1) % 2);
    }
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int u, v;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        vertice[u].push_back(v);
        vertice[v].push_back(u);
    }
    dfs(1, 0, 1);
    cout << g1.size() * g2.size() - (n - 1); 
}
