#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;
const int M = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct Mat {
    vector<vi>A;
    int row() const {return sz(A);} 
    int col() const {return sz(A[0]);}
    auto& operator[] (int i) {return A[i];}
    const auto & operator[] (int i) const {return A[i];}
    Mat() = default;
    Mat(int r, int c): A(r, vi(c)) {}
    Mat(const vector<vi> &d): A(d) {}
    static Mat id(long long n) {
        // Matrix identity
        Mat a = Mat(n, n);
        while (n--) a[n][n] = 1;
        return a;
    }
    Mat operator * (const Mat &b) {
        Mat a = *this;
        assert(a.col() == b.row()); 
        Mat c(a.row(), b.col());
        rep(i, 0, a.row())
            rep(j, 0, b.col())
                rep(k, 0, a.col()) {
                    c[i][j] += (a[i][k] * b[k][j]) % M;
                    c[i][j] %= M;
                }
        return c;
    }
    Mat pow(long long exp) {
        assert(row()==col());  
        Mat b = *this, ans = id(row());
        for (; exp > 0; exp >>= 1, b=b*b)
            if (exp&1) ans = ans * b;
        return ans;
    }
};
int n, m, k;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m >> k;
    Mat A(n, n);
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        A[x][y] += 1;
        // A[y][x] = 1;
    }
    A = A.pow(k);
    cout << A[0][n-1];
}
