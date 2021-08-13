#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 200000;

using namespace std;

int n, m;
int fee[N], c[N];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    fee[1] = true;
    for (int i = 1; i <= n; i++) c[i] = 1;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        if (c[x] >= 1 && fee[x] == true) {
           fee[y] = true;
        } else if (c[x] < 1) fee[x] = false;
        c[x]--; c[y]++;
        if (c[x] == 0) fee[x] = false;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += fee[i];
    }
    cout << res;
}
