// havent done yet !!
#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

ll count(double t, double x, double y) {
    double k1 = ceil(x / t);
    int k2 = y / t;
    return (y - x + 1) - (k2 - k1 + 1);
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int res = 0;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = a; i <= b; i++) {
        res += count(i, c, d);
        cout << i << ": "  << count(i, c, d) << endl;
    }
    cout << res;
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/