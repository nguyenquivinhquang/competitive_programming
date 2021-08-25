#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 200009;
const int INF = 1e9;
struct segTree {
    vector<int> it; int n;
    segTree(int n): it(n * 4, INF) {
        this->n = n;
    }
    void update(int node, int l, int r, int pos, int val) {
        if (pos < l || pos > r) return;
        if (l == r) {
            it[node] = val;
            return;
        }
        int mid = (l + r) >> 1;
        update(node * 2, l, mid, pos, val);
        update(node * 2 + 1, mid + 1,r,  pos, val);
        it[node] = min(it[node * 2], it[node*2+1]);
    }
    int get(int node, int l, int r, int u, int v) {
        if (v < l || u > r) return INF;
        if (u <= l && r <= v) return it[node];
        int mid = (l + r) >> 1;
        return min(get(node * 2, l, mid, u, v), get(node * 2 + 1, mid + 1, r, u, v));
    }
};
int a[N];
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, q; cin >> n >> q;
    segTree tree(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tree.update(1, 1, n, i, a[i]);
    }
    while (q--) {
        int cond, x, y; cin >> cond >> x >> y;
        if (cond == 1) {
            a[x] = y;
            tree.update(1, 1, n, x, y);
        } else {
            cout << tree.get(1, 1, n, x, y) << "\n";
        }
    }
}
