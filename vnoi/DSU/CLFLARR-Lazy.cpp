//https://www.spoj.com/problems/CLFLARR/
// this sol use IT Lazy Propagation 
#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 200005;

using namespace std;
struct Node {
    int val, lazy;
} nodes[N * 4];
int n, q, l, r, c;
void down(int id) {
    int t = nodes[id].lazy;
    if (t == -1)
        return;
    nodes[id * 2].lazy = t;
    nodes[id * 2].val = t;

    nodes[id * 2 + 1].lazy = t;
    nodes[id * 2 + 1].val = t;
    nodes[id].lazy = -1;
}
void update(int id, int l, int r, int u, int v, int val) {
    if (v < l || r < u) {
        return;
    }
    if (u <= l && r <= v) {
        nodes[id].val = val;
        nodes[id].lazy = val;
        return;
    }
    int mid = (l + r) / 2;

    down(id);  
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);

    nodes[id].val = val;
}
int get(int id, int l, int r, int pos) {
    if (pos < l || pos > r)
        return 0;
    if (l == r)
        return nodes[id].val;
    down(id);
    int mid = (l + r) / 2;
    return max(get(id * 2, l, mid, pos), get(id * 2 + 1, mid + 1, r, pos));
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    memset(nodes, -1, sizeof(nodes));
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        cin >> l >> r >> c;
        update(1, 1, n, l, r, c);
    }
    for (int i = 1; i <= n; i++)
        cout << get(1, 1, n, i) << "\n";
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/