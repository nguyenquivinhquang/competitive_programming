#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

int n,m ;
set<ll> trace;
ll res = 1e12;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        ll temp; cin >> temp;
        trace.insert(temp);
    }
    for (int i = 1; i <= m; i++){
        ll temp; cin >> temp;
        auto it = trace.lower_bound(temp);
        res = min(res, abs(temp-*it));
        if (it == trace.begin()) continue;
        it--;
        res = min(res, abs(temp-*it));
    }
    cout << res;

}
