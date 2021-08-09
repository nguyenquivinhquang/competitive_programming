#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 100009;

using namespace std;

int n, m;
vector<int> edge[N];
void longgest_path() {
    vector<int> pre(n + 2, -1), d(n + 2, 0);
    set<pp> q;
    q.insert({0, 1});
    while (q.size()) {
        int u = q.begin()->second;
        q.erase(q.begin());
        for (auto v : edge[u]) {
            if (d[v] > d[u] - 1) {
                pre[v] = u;
                q.erase({d[v], v});
                d[v] = d[u] - 1;
                q.insert({d[v], v});
            }
        }
    }
    if (d[n] == 0) {
        cout << "IMPOSSIBLE";
        return;
    }
    vector<int> trace;
    int u = n;
    while (u != 1) {
        trace.push_back(u);
        u = pre[u];
    }
    trace.push_back(1);
    reverse(trace.begin(), trace.end());
    cout << trace.size() << "\n";
    for (auto v : trace)
        cout << v << ' ';
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int x, y;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
        // edge[y].push_back(x);
    }
    longgest_path();
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/