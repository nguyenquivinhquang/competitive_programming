#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 100009;

using namespace std;
int m, n;
vector<int> g[N], gr[N];
vector<bool> used;
vector<int> order, component;
vector<vector<int>> res;
void dfs1(int v) {
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i)
        if (!used[g[v][i]])
            dfs1(g[v][i]);
    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    for (size_t i = 0; i < gr[v].size(); ++i)
        if (!used[gr[v][i]])
            dfs2(gr[v][i]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    used.assign(n, false);
    for (int i = 0; i < n; ++i)
        if (!used[i])
            dfs1(i);
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        int v = order[n - 1 - i];
        if (!used[v]) {
            dfs2(v);
            res.push_back(component);
            component.clear();
            if (res.size() == 2) break;
        }
    }
    if (res.size() == 1)
        cout << "YES";
    else {
        cout << "NO \n";
        cout << res[1][0] + 1 << " " << res[0][0] + 1;
    }
}
/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/