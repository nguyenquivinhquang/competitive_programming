#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 200009;

using namespace std;
int n, k, r, satify = 0, a[N], res = 1e7, cond[N];
map<int, int> trace;
queue<int> q;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> k >> r;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= r; i++) {
        int b, Q;
        cin >> b >> Q;
        trace[b] = Q;
    }
    
    r = trace.size();
    for (int i = 1; i <= n; i++) {
        q.push(a[i]);
        if (cond[a[i]] + 1 == trace[a[i]]) satify++;
        cond[a[i]]++;
        if (satify == r) res = min(res,int(q.size()));
        while (1) {
            int x = q.front();
        
            if (cond[x] <= trace[x] || q.size() == 0 || satify < r) break;

            q.pop();
            if (--cond[x] < trace[x]) satify--;
            if (satify == r) res = min(res,int(q.size()));
        }
    }
    if (res != 1e7) cout << res;
    else cout << "impossible";
}
