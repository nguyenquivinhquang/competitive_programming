#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 200009;

using namespace std;
int n, res = 1;
set<int, greater<>> trace;
int a[N];

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    trace.insert(a[1]);
    for (int i = 2; i <= n; i++) {
        auto it = trace.lower_bound(a[i] - 1);
        if (it == trace.end() || *it != a[i] - 1) res++;
        else trace.erase(it);
        trace.insert(a[i]);
    }
    cout << res;
}
