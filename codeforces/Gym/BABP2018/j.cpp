#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;


signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    double a ,b, c, d, s, res;
    cin >> a >> b >> c >>d;
    s = (a + b +c +d) / 2.0;
    res = sqrt((s -a ) * (s - b) * (s - c) * (s- d));
    cout << fixed << setprecision(12) << res;
}
