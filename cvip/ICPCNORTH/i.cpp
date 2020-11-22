#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1000;
typedef vector<double> vd;



const double eps = 1e-12;
struct coor {
    double x, y, z, hs;
    int d;

} a, b, c, n, ptmp, h, HA;
double cos_alpha, R;

void findZScale(coor& temp) {
    temp.z = sqrt(1 - temp.x * temp.x - temp.y * temp.y);
    if (temp.d == 0) temp.z *= -1;
    // temp.x *= 100, temp.y *= 100, temp.z *= 100;
    cout << temp.x << " " << temp.y << " " << temp.z << endl;
}
void findVectoN() {
    n.x = (b.y * c.z - c.y * b.z);
    n.y = -((b.x * c.z - c.x * b.z));
    n.z = (b.x * c.y - c.x * b.y);
}
void findptmp() {
    ptmp = n;
    ptmp.hs = -(a.x * n.x + a.y * n.y + a.z * n.z);
}
void findH() {
    double t = -ptmp.hs / (n.x * n.x + n.y * n.y + n.z * n.z);
    h.x = n.x * t;
    h.y = n.y * t;
    h.z = n.z * t;
}
void findHA() {
    HA.x = a.x - h.x;
    HA.y = a.y - h.y;
    HA.z = a.z - h.z;
    R = sqrt(HA.x * HA.x + HA.y * HA.y + HA.z * HA.z);
}
int solveLinear(vector<vd>& A, vd& b, vd& x) {
    int n = sz(A), m = sz(x), rank = 0, br, bc;
    if (n) assert(sz(A[0]) == m);
    vi col(m);
    iota(all(col), 0);

    rep(i, 0, n) {
        double v, bv = 0;
        rep(r, i, n) rep(c, i, m) if ((v = fabs(A[r][c])) > bv)
            br = r,
            bc = c, bv = v;
        if (bv <= eps) {
            rep(j, i, n) if (fabs(b[j]) > eps) return -1;
            break;
        }
        swap(A[i], A[br]);
        swap(b[i], b[br]);
        swap(col[i], col[bc]);
        rep(j, 0, n) swap(A[j][i], A[j][bc]);
        bv = 1 / A[i][i];
        rep(j, i + 1, n) {
            double fac = A[j][i] * bv;
            b[j] -= fac * b[i];
            rep(k, i + 1, m) A[j][k] -= fac * A[i][k];
        }
        rank++;
    }

    x.assign(m, 0);
    for (int i = rank; i--;) {
        b[i] /= A[i][i];
        x[col[i]] = b[i];
        rep(j, 0, i) b[j] -= A[j][i] * b[i];
    }
    return rank;  // (multiple solutions if rank < m)
}
void solve() {
    cin >> a.x >> a.x >> b.x >> b.y >> c.x >> c.y;
    cin >> a.d >> b.d >> c.d;
    findZScale(a);
    findZScale(b);
    findZScale(c);
    cos_alpha = (b.x * c.x + b.y * c.y * b.z * c.z) / 1;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        solve();
    }
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/