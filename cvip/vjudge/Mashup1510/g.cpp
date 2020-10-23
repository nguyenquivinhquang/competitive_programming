#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 200005;
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, a[N];
    ll res = 0;
    map<ll, int> trace;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        trace[i + a[i]]++;
        if (i - a[i] >= 0)
            res += trace[i - a[i]];
    }
    cout << res;
}