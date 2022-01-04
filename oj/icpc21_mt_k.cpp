#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 20000;
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
int toNode(int x, int y) {
    return x * m + y;
}
char check[N][N];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m >> k;
    Mat A(n * m, m * n);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) cin >> check[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c = check[i][j];
            int x = i, y = j;
            if (c == 'R') {
                y++;
                if (y < m) {
                    if (check[x][y] == '#') continue;
                    int u = toNode(i, j), v = toNode(x, y);
                    A[u][v]++;
                }
            } else if (c == 'U') {
                x--;
                if (x >= 0) {
                    if (check[x][y] == '#') continue;
                    int u = toNode(i, j), v = toNode(x, y);
                    A[u][v]++;
                }
            } else if (c == 'D') {
                x++;
                if (x < n){
                    if (check[x][y] == '#') continue;
                    int u = toNode(i, j), v = toNode(x, y);
                    A[u][v]++;
                }
            } else if (c == 'L') {
                y--;
                if (y >= 0) {
                    if (check[x][y] == '#') continue;
                    int u = toNode(i, j), v = toNode(x, y);
                    A[u][v]++;
                }
            } else if (c == '+') {
                if (x - 1 >= 0 && check[x-1][y] != '#') {
                    
                    int u = toNode(i, j), v = toNode(x - 1, y);
                    A[u][v]++;
                }
                if (x + 1 < n && check[x+1][y] != '#') {
                    int u = toNode(i, j), v = toNode(x + 1, y);
                    A[u][v]++;
                }
                if (y - 1 >= 0 && check[x][y-1] != '#'){
                    int u = toNode(i, j), v = toNode(x, y - 1);
                    A[u][v]++;
                }
                if (y + 1 < m && check[x][y+1] != '#') {
                    int u = toNode(i, j), v = toNode(x, y + 1);
                    A[u][v]++;
                }
            } 
        }
    }
    
    A = A.pow(k);
    ll res = 0;
    for (int i = 0; i < n * m; i++) {
        for (int j = 0; j < m * n; j++) {
            res += A[i][j];
            res %= M;
            // cout << A[i][j] << " ";
        }
        // cout << "\n";
    }
    cout << res;
}
