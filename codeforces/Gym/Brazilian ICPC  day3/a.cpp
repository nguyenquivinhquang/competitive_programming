#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 100009;

using namespace std;

int n, a[N];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll res = 0, m = 1e5;
    for (int i = 1; i <= n; i++) {
        ll t;
        if (a[i]&1)  t = a[i];
        else t = a[i]-1;
        m = min(m, t);
        res += t;
    }
    if (!(res&1)) res-=m;
    cout << res;
}
