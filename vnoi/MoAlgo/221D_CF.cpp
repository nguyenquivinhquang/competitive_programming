//https://codeforces.com/problemset/problem/221/D

#include <bits/stdc++.h>

const int N = 100005;

using namespace std;
int n, S, m, a[N], result = 0;

unordered_map<int, int> trace;

struct Query {
    int l, r, id, val;
};
bool cmp(Query &x, Query &y) {
    if (x.l / S != y.l / S)
        return x.l / S < y.l / S;
    return x.r < y.r;
}
bool cmpid(Query &x, Query &y) {
    return x.id < y.id;
}

Query query[N];
void ope(int x, int v) {
    if (x < 1) return;
    int t = trace[x];
    if (t == x)
        result--;
    trace[x] += v, t += v;
    if (t == x)
        result++;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int l, r;
    cin >> n >> m;
    S = sqrt(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= m; j++) {
        cin >> l >> r;
        query[j].l = l, query[j].r = r, query[j].id = j;
    }
    sort(query + 1, query + 1 + m, cmp);

    int cur_l = 0, cur_r = -1;
    for (int i = 1; i <= m; i++) {
        while (cur_l > query[i].l) {
            cur_l--;
            ope(a[cur_l], 1);
        }
        while (cur_r < query[i].r) {
            cur_r++;
            ope(a[cur_r], 1);
        }
        while (cur_l < query[i].l) {
            ope(a[cur_l], -1);
            cur_l++;
        }
        while (cur_r > query[i].r) {
            ope(a[cur_r], -1);
            cur_r--;
        }
        query[i].val = result;
    }
    sort(query + 1, query + 1 + m, cmpid);
    for (int i = 1; i <= m; i++)
        cout << query[i].val << "\n";
}