#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 100009;

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n;
    int x[N], y[N], xr, yr;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(x + 1, x + 1 + n);
    sort(y + 1, y + 1 + n);
    if (n % 2 == 0) {
        int p1 = n / 2, p2 = n / 2 + 1;
        int mid = (p1 + p2) / 2;
        xr = x[mid], yr = y[mid];
    } else {
        int mid = n / 2 + 1;
        xr = x[mid], yr = y[mid];
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res += abs(x[i] - xr) + abs(y[i] - yr);
    cout <<res;
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/