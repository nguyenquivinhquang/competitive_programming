#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
 
using namespace std;
 
const int maxn = 2E5+5;
 
struct node {
    int pre, suf, num;
    bool okAll;
    node(int A, int B, int C, bool D) {
        pre = A;
        suf = B;
        num = C;
        okAll = D;
    }
    node(){};
    ~node(){};
};
 
node it[4*maxn];
int a[maxn];
 
 
void Merge(node &C, node Le, node Ri, int len, bool ok) {
    C.pre = Le.pre;
    if (Le.okAll && ok) {
        C.pre += Ri.pre;
    }
 
    C.suf = Ri.suf;
    if (Ri.okAll && ok) {
        C.suf += Le.suf;
    }
 
    C.okAll = C.suf == len;
 
    C.num = Le.num + Ri.num;
    if (ok) {
        C.num += Le.suf * Ri.pre;
    }
}
 
void build(int l, int r, int id) {
    if (l > r) return;
    if (l == r) {
        it[id].pre = it[id].suf = 1;
        it[id].num = 1;
        it[id].okAll = 1;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, id*2);
    build(mid+1, r, id*2+1);
    Merge(it[id], it[id*2], it[id*2+1], r-l+1, a[mid] <= a[mid+1]);
}
 
void update(int pos, int l, int r, int id) {
    if (l > pos || r < pos) return;
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    update(pos, l, mid, id*2);
    update(pos, mid+1, r, id*2+1);
    Merge(it[id], it[id*2], it[id*2+1], r-l+1, a[mid] <= a[mid+1]);
}
 
node get(int i, int j, int l, int r, int id) {
    if (l > j || r < i) return node(0, 0, 0, 0);
    if (l >= i && r <= j) return it[id];
    node tmp;
    int mid = l + r >> 1;
    node Le = get(i, j, l, mid, id*2);
    node Ri = get(i, j, mid+1, r, id*2+1);
    Merge(tmp,  get(i, j, l, mid, id*2), get(i, j, mid+1, r, id*2+1), r-l+1, a[mid] <= a[mid+1]);
    return tmp;
}
 
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("t.inp", "r", stdin);
    int n, q;
    cin >> n >> q;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    build(0, n-1, 1);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int pos, val;
            cin >> pos >> val;
            pos--;
            a[pos] = val;
            update(pos, 0, n-1, 1);
        }
        if (t == 2) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << get(l, r, 0, n-1, 1).num << "\n";
        }
    }
    return 0;
}