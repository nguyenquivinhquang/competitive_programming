#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 100009;

using namespace std;
int n, m;
set<int> vertice[N];
vector<int> res;
void dfs(int u) {
    while (vertice[u].size()) {
        int v = *vertice[u].begin();
        vertice[v].erase(u);
        vertice[u].erase(v);
        dfs(v);
    }
    res.push_back(u);
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        vertice[x].insert(y);
        vertice[y].insert(x);
    }
    for (int i = 1; i <= n; i++) {
        if (vertice[i].size() % 2) {
            cout << "IMPOSSIBLE";
            exit(0);
        }
    }
    dfs(1);
    if (res.size() != m + 1) {
        cout << "IMPOSSIBLE";
        exit(0);
    }
    for (auto v : res) {
        cout << v << " ";
    }
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/