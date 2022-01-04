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
int subtree[N];
int n;
void dfs1(int u, int preU) {
    subtree[u] = 1;
    for (auto v : vertice[u]) {
        if (v == preU) continue;
        dfs1(v, u);
        subtree[u] += subtree[v];
    }
}
int get_centroid(int u, int preU) {
    for (auto v : vertice[u]) {
        if (v == preU) continue;
        if (subtree[v] * 2 >= n) {
            return get_centroid(v, u);
        }
    }
    return u;
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
    dfs1(1, -1);
    cout << get_centroid(1, 0);
}
