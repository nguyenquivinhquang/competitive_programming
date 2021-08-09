#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 500000;

using namespace std;
int D[N], L[N], it[N * 4 + 5], n, a[N], b[N], R[N];
void findLR(int t[N]) {
    int top = 0;
    D[0] = 0;
    for (int i = 1; i <= n; ++i) {
        while (top > 0 && t[D[top]] >= t[i]) --top;
        L[i] = D[top] + 1;
        D[++top] = i;
    }
    D[0] = n + 1;
    top = 0;
    for (int i = n; i >= 1; --i) {
        while (top > 0 && t[D[top]] >= t[i]) --top;
        R[i] = D[top] - 1;
        D[++top] = i;
    }
}
void build(int id, int l, int r) {
    if (l == r) {
        it[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    it[id] = max(it[id * 2], it[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return -1e9;
    if (u <= l && r <= v) return it[id];
    int mid = (l + r) >> 1;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
signed main() {
    // ios_base::sync_with_stdio(false), cin.tie(NULL);
    int res = -123;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    findLR(b);
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        if (L[i] == R[i]) continue;
        int x = get(1, 1, n, L[i], i - 1), y = get(1, 1, n, i + 1, R[i]);
        int v = min(b[i], x + y);
        v = max(min(b[i], x + a[i]), v);
        v = max(min(b[i], y + a[i]), v);
        res = max(res, v);
    }

    cout << res;
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/