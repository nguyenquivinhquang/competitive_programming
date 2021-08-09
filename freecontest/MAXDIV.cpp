#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 300007;

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    ll res = 0;
    int a[N], k, n;
    queue<int> q;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    q.push(n + 1);
    for (int i = n; i >= 1; i--) {
        if (a[i] % k == 0)
            q.push(i);
        if (q.size() > 2) q.pop();
        res += q.front() - i;
    }
    cout << res;
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/