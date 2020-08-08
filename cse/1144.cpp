#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
int n, q, p[N], a[N], b[N];
int k, t[16*N];
char c[N];
set<int> s;
vector<int> r;
 
int ask(int i, int u, int v, int w) {
    if (u < v) {
        int m = (u+v)/2;
        if (w <= r[m]) return ask(2*i, u, m, w);
        return ask(2*i+1, m+1, v, w) + t[2*i];
    }
    return t[i];
}
 
void mov(int i, int u, int v, int w, int j) {
    if (u < v) {
        int m = (u+v)/2;
        if (w <= r[m]) {
            mov(2*i, u, m, w, j);
        } else {
            mov(2*i+1, m+1, v, w, j);
        }
    }
    t[i] += j;
}
 
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < q; i++) {
        scanf("\n%c %d %d", &c[i], &a[i], &b[i]);
        a[i]--;
        if (c[i] == '!') continue;
        s.insert(a[i]);
        s.insert(b[i]);
    }
    for (int i : s) {
        r.push_back(i);
    }
    r.push_back(1e9);
    k = r.size();
    for (int i = 0; i < n; i++) {
        mov(1, 0, k-1, p[i], +1);
    }
    for (int i = 0; i < q; i++) {
        if (c[i] == '?') {
            int qa = ask(1, 0, k-1, a[i]);
            int qb = ask(1, 0, k-1, b[i]);
            printf("%d\n", qb-qa);
        }
        if (c[i] == '!') {
            mov(1, 0, k-1, p[a[i]], -1);
            p[a[i]] = b[i];
            mov(1, 0, k-1, p[a[i]], +1);
        }
    }
    return 0;
}