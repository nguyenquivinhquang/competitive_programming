#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 300000;

using namespace std;
vector<int> vertice[N];
int n,m;
void dfs(int u, int preU) {
    cout << u << " ";
    for (auto v : vertice[u]) {
        if (v == preU) continue;
        dfs(v, u);
        cout << u << " ";
    }
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vertice[x].push_back(y);
        vertice[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) sort(vertice[i].begin(), vertice[i].end());
    dfs(1, -1);
}
