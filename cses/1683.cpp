#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 100009;

using namespace std;
int m, n, kingdom[N], k = 0;
vector<int> g[N], gr[N];
vector<bool> used;
vector<int> order, component;
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
            // res.push_back(component);
            k++;
            for (auto v : component) {
                kingdom[v] = k;
            }
            component.clear();
           
        }
    }
    cout << k << "\n";
    for (int i = 0; i < n; i++)
        cout << kingdom[i] << " ";
}
/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/