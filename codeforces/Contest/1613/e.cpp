#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1009;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, m;
char a[N][N];
bool visit[N][N], ok[N][N];
// vector<vector<char>> a;

void dfs(int x, int y) {
    visit[x][y] = true;
    if (a[x][y] == '#') {
        ok[x][y] = false;
        return;
    }
    if (a[x][y] == 'L') {
        ok[x][y] = true;
        return;
    }
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i * j != 0) continue;
            if (i + j == 0) continue;
            int u = x + i, v = y + j;
            if (u > n || u < 1 || v > m || v < 1 || a[u][v] == '#') continue;
            if (visit[x][u] == false) dfs(u, v); 

        }
    }
    int cannGo = 0, toL = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int u = x + i, v = y + j;
            if (u > n || u < 1 || v > m || v < 1 || a[u][v] == '#') continue;
            toL++;
            if (ok[u][v]) toL--;
        }
    }
    if (toL <= 1) ok[x][y] = true;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (visit[i][j] == false) dfs(i,j);
    }
    for (int i = 1; i <= n; i++ ) {
        for (int j = 1; j <= n; j++) {
            if (ok[i][j] == true && a[i][j] =='.') cout <<'+';
            else cout << a[i][j];
            ok[i][j] = visit[i][j] = false;
        }
        cout << "\n";
    }
    cout << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
