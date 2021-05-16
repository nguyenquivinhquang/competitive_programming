#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

using namespace std;
const int N = 1005;
int parent[N], n, Rank[N];
vector<pp> removeEdge;
set<int> root;
vector<int> res;
void makeSet() {
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}
int find(int x) {
    if (x != parent[x])
        parent[x] = find(parent[x]);
    return parent[x];
}
bool join(int u, int v){
    u = find(u), v = find(v);
    if (u == v) return false;
    if (Rank[u] == Rank[v]) Rank[u]++;
    if (Rank[u] > Rank[v]) parent[v] = u; else parent[u] = v;
    return true;
}
signed main() {
    //ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    makeSet();
    int x, y;
    for (int i = 1; i < n; i++){
        cin >> x >> y;
        if (!join(x, y))
            removeEdge.push_back({x, y});
    }
    for (int i = 1; i <= n; i++)
        root.insert(find(i));
    for (auto v: root)
        res.push_back(v);
    cout << res.size() - 1<< "\n";
    res.push_back(*root.begin());
    for (int i = 0; i < res.size() - 2; i++){
        cout << removeEdge[i].first << " " << removeEdge[i].second << " " << res[i] << " " << res[i+1] << "\n";
    }

}
