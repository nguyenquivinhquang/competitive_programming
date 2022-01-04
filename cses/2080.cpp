#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define map unordered_map
const int N = 200001;

typedef int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vector<ll> vertice[N];
map<ll,ll> dis[N];
int n, k;
ll res = 0;
void dfs(int u, int preU) {
    map<ll,ll> temp;
    for (auto v: vertice[u]) {
        if (v == preU) continue;
        dfs(v, u);
        if (dis[u].size() < dis[v].size()) swap(dis[u], dis[v]);
        for (auto val: dis[v]) {
            ll rem = k - val.first - 2;
            res += dis[u][rem] * val.second;
            if (val.first + 1== k) res += val.second;
        }
        for (auto val: dis[v]) {
            dis[u][val.first] += val.second;
        }
    }
    for (auto v : dis[u]) {
        temp[v.first + 1] = v.second;
    }
    dis[u] = temp;
    dis[u][0] = 1;
}
int subtree[N];
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
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        vertice[x].push_back(y);
        vertice[y].push_back(x);
    }
    dfs1(1, 0);
    int centroid = get_centroid(1, 0);
    dfs(centroid, -1);
    cout << res;
}
