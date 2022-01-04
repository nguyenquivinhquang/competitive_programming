#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1009;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, l, b, d, s, res = 0;
vector<pair<int, pii>> vertice[N];
vector<int> L;
bool bfs(int x, int y) {

    vector<int> D;
    D.assign(n + 1, -1);
    D[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto edge : vertice[v]) {
            int u = edge.first;
            if (D[u] != -1 ) continue;
            auto [l1, l2] = edge.second;

            if (l1 <= x && y <= l2) {
                D[u] = 1;
                if (u == d) return true;
                q.push(u);
            }
        }
    }

    return D[d]  != -1;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> l >> b >> s >> d; 
    s--, d--;
    set<int> temp;
    for (int i = 1; i <= l; i++) {
        int u, v,  x, y; 
        cin >> u >> v >> x >> y;
        temp.insert(x); temp.insert(y);
        u--, v--;
        vertice[u].push_back({v, {x, y}});
    }
    for (auto v : temp) {
        L.push_back(v);
    }
    map<int, int> dup;
    for (int i = 0; i < L.size() - 1; i++) {
        if (bfs(L[i], L[i+1]) == true) {
            res += L[i+1] - L[i] + 1;
            if (dup[L[i]] > 0) res--;
            dup[L[i+1]] = 1; dup[L[i]] = 1;
        }
    }


    for (int i = 0; i < L.size(); i++) {
        if (bfs(L[i], L[i]) == true) {
            res ++;
            if (dup[L[i]] > 0) res--;
            dup[L[i]] = 1;
        }
    }


    cout << res;
}
