#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 200009;

using namespace std;
int n;
vector<int> verice[N];
vector<pp> setA, setB, remainEdge;
bool marked[N];
void makeEdge(int root, int u, int v) {
    setA.push_back({root, u});
    setA.push_back({u, v});
    setB.push_back({root, v});
    setB.push_back({u, v});
    
}
void dfs(int u, int preU) {
    vector<int> remainVertex;
    for (auto v : verice[u]) {
        if (v == preU) continue;
        dfs(v, u);
        if (marked[v] == false) remainVertex.push_back(v);
    }
    for (int i = 0; i < remainVertex.size(); i+= 2) {
        if (i == remainVertex.size() - 1) {
            int x = remainVertex[i];
            makeEdge(u, x, preU );
            marked[x] = marked[u] = true;
            break;
        }
        int x = remainVertex[i], y = remainVertex[i + 1];
        makeEdge(u, x, y);
        marked[x] = marked[y] = true;
    }

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int x, y;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        verice[x].push_back(y);
        verice[y].push_back(x);
    }
    if (n % 2 == 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }
        
    dfs(1, 0);

    for (auto e : setA) {
        cout << e.first << " " << e.second << "\n";
    }
    for (auto e : setB) {
        cout << e.first << " " << e.second << "\n";
    }
}