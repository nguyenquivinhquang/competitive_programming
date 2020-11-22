#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, m, x1, x2, y1, y2;
    cin >> n >> m;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 % 2 != x2 % 2 || y1 % 2 != y2 % 2) {
        cout << -1;
        return 0;
    }
    ll step = abs(x1 - x2) / 2 + (abs(y1 - y2)) / 2;
    cout << step;
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/