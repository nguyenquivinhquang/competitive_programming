#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pp pair<int, int>

const int N = 5005;

using namespace std;
struct Vertice {
    vector<int> Next;
    int val[N];
    Vertice() {
        memset(val, 0, sizeof(val));
    }
};
Vertice vertice[N];
pp infor[N];
bitset<N + 3> fee;
int n, m;

void buildGraph(int u, int depth, int root, int val) {
    queue<pp> q;
    q.push({root, 0});
    while (q.size() != 0) {
        auto u = q.front();
        q.pop();
        if (u.second == depth) continue;
        for (auto v : vertice[u.first].Next) {
            if (fee[v] == 1) continue;
            fee[v] = 1;
            vertice[root].val[v] = val;
            q.push({v, u.second + 1});
        }
    }
}
void Dijkstra() {
    int u;
    set<pp> q;
    vector<int> d(n + 2, 1e9);
    q.insert({0, 1});
    d[1] = 0;
    while (q.size() != 0) {
        int u = q.begin()->second;
        q.erase(q.begin());
        for (auto v : vertice[u].Next) {
            int len = vertice[u].val[v];
            if (d[u] + len < d[v]) {
                q.erase({d[v], v});
                d[v] = d[u] + len;
                q.insert({d[v], v});
            }
        }
    }
    cout << d[n];
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    int x, y, len;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> infor[i].first >> infor[i].second;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        vertice[x].Next.push_back(y);
        vertice[y].Next.push_back(x);
    }
    // cout << "tes" << endl;
    for (int i = 1; i <= n; i++) {
        fee.reset();
        fee[i] = 1;
        buildGraph(i, infor[i].second, i, infor[i].first);
    }
    
    for (int i = 1; i <= n; i++) {
        vertice[i].Next.clear();
        for (int j = 1; j <= n; j++) {
            if (vertice[i].val[j] != 0)
                vertice[i].Next.push_back(j);
        }
    }
    // for (auto v : vertice[1].Next)
    // 	cout << v << " ";
    Dijkstra();
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!

4 5
2 2 
2 2
5 2
2 2
1 2
2 4
3 2
1 3
3 4
*/
