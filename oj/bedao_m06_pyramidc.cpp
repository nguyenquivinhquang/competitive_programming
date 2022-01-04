#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
double a, b, c, x, y;
int solve(double i) {
    c = i;
    b = x + y - i;
//  cerr << i << endl;
//  if (abs(i - 4.6) < 1e-5) {
//      cerr <<"";
//  }
    if ( c*c - b*b <= 0) return 1;
    a = sqrt(c * c - b * b);
    if (a > b) swap(a ,b);
    if (abs(a + b) - y < 1e-1 && abs(c -a) - x< 1e-1) {
        cout << fixed << setprecision(9) << a << " " << b << " " <<c;
        exit(0);
    } 
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> x >> y;
    double l  = x, r = x + y;
    while (r - l > 1e-3) {
        double mid = (l + r) / 2.0;
        if (solve(mid)) l = mid + 0.5;
        else r = mid;
    }
}
