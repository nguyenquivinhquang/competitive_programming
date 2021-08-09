#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
int n, q, a[N];
vector<int> bit;

void add(int idx, int pos) {
    for (; idx < n; idx = idx | (idx + 1))
        bit[idx] += pos;
}
int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += bit[r];
    return ret;
}
int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    bit.assign(n, 0);
    int type, x, y;
    while (q--) {
        cin >> type >> x >> y;
        if (type == 1)  {
            add(x, y - a[x]);
            a[x] = y;
        } else {
            cout << sum(x, y) << "\n";
        }
    }
}
