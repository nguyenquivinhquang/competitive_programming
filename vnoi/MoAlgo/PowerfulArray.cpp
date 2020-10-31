#include <bits/stdc++.h>
#define ll long long
#define int long long
const int N = 200010;

using namespace std;
int S = 500;
struct Query {
     int l, r, id, val;
} query[N];
bool cmp(Query x, Query y) {
     if (x.l / S != y.l / S)
          return x.l / S < y.l / S;
     return x.r / S < y.r / S;
}
bool cmpid(Query x, Query y) {
     return x.id < y.id;
}
int n, a[N], m, trace[1000009];
ll sum = 0;

void update(int x, int ope) {  // ope: 1 add, -1 remove
     int k = trace[x];
     sum -= k * k * x;
     k += ope;
     trace[x] = k;
     sum += k * k * x;
}
signed main() {
     ios_base::sync_with_stdio(false), cin.tie(NULL);
     memset(trace, 0, sizeof(trace));
     int l, r;
     cin >> n >> m;
     for (int i = 1; i <= n; i++)
          cin >> a[i];
     for (int i = 1; i <= m; i++) {
          cin >> l >> r;
          query[i].l = l, query[i].r = r, query[i].id = i;
     }
     sort(query + 1, query + 1 + m, cmp);
     int cur_l = 1, cur_r = -1;
     for (int i = 1; i <= m; i++) {
          while (cur_l > query[i].l) {
               cur_l--;
               update(a[cur_l], +1);  //add
          }
          while (cur_r < query[i].r) {
               cur_r++;
               update(a[cur_r], 1);  // add
          }
          while (cur_l < query[i].l) {
               update(a[cur_l], -1);  // remove
               cur_l++;
          }
          while (cur_r > query[i].r) {
               update(a[cur_r], -1);  // remove
               cur_r--;
          }
          query[i].val = sum;
     }
     sort(query + 1, query + 1 + m, cmpid);
     for (int i = 1; i <= m; i++)
          cout << query[i].val << "\n";
}