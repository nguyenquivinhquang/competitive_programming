#include <bits/stdc++.h>
using namespace std;
#define int ll 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 200000;
#define inf 1e9
int n, cost[N], parent[N], num_child[N], inTour[N], outTour[N], visit = 0;
vector<int> vertice[N], it(N*4, 1e10);
map<int,int> idx;
set<int> q;
 
void update (int node, int l, int r, int idx, int val) {
    if (idx > r || idx < l) return;
    if (l == r) {
        it[node] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(node * 2, l, mid, idx, val);
    update(node * 2 + 1, mid + 1, r,idx, val);
    it[node] = min(it[node * 2] , it[node*2+1]);
 
}
ll get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return inf;
    }
    if (u <= l && r <= v) {
        return it[id];
    }
    int mid = (l + r) >> 1;
 
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
void dfs(int u, int preU) {
    visit++;
    inTour[u] = visit;

    for (auto v : vertice[u]) {
        if (v == preU) continue;
        dfs(v, u);
    }
    outTour[u] = visit;
}

signed main() {
    
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int u; cin >> u;
        vertice[u].push_back(i);
        parent[i] = u;
        num_child[u]++;
    }
    
    vector<int> temp;
    dfs(1 ,0);
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
        idx[cost[i]] = i;
        q.insert(cost[i]);
        update(1,1,n, inTour[i], cost[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        int u = 1;
        while(num_child[u]) {
            int min_value = get(1, 1, n, inTour[u] + 1, outTour[u]);
            u = idx[min_value];
            // cout << min_value << endl;
        }
        
        cout << u << " ";
        update(1,1,n,inTour[u], inf);
        num_child[parent[u]]--;
    }
}