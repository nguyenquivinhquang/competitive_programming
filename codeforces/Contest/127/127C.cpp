#include<bits/stdc++.h>
// Have not Ac yet
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1000;
double t1, t2, x1, x2, t0;
signed main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin.exceptions(cin.failbit);
    int res = 10000000, y1 = 10000000, y2 = 10000000;
    cin >> t1 >> t2 >> x1 >> x2 >> t0;
    for (int i = 1; i <= x1; i++) {
        double xt = i;
        int a = xt*(t1 - t0) / (t0 - t2) + 0.5;
        if (a > x2) continue;
        double check = (xt * t1 + a * t2 ) / (xt + a);
        if (check < t0 ) a++;
        if (max(a, i) < res) {
            res = max(a , i);
            y1 = i, y2 = a;
        }
    }
    cout << y1 << " " << y2;
}

