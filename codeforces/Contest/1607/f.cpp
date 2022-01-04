#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
const int N = 2009;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, m, big[N][N]; short color[N][N];
char dir[N][N];
bool check(int x, int y) {
    if (x > n || y > m || x < 1 || y < 1) return false;
    return true;
}
void getNext(int &x, int &y, char c) {
    if (c == 'L') y--;
    if (c == 'R') y++;
    if (c == 'U') x--;
    if (c == 'D') x++;
}
void dfs(int i, int j) {
    color[i][j] = 1;
    int x = i, y = j;
    getNext(x, y, dir[x][y]);
    
    if (!check(x, y)){
        color[i][j] = 2;
        return;
    }
    if (color[x][y] == 2) {
        color[i][j] = 2;
        return;
    }
    if (color[x][y] == 1) {
        int total = 1;
        while(!(x == i && y == j)) {
            getNext(x, y, dir[x][y]);
            total++;
        }
        big[i][j] = total;
        color[i][j] = 2;
        getNext(x, y, dir[x][y]);
        while(!(x == i && y == j)) {
            big[x][y] = total;
            color[x][y] = 2;
            getNext(x, y, dir[x][y]);
            //big[x][y] = total;
        }
        
        return;
    }
    dfs(x, y);
    color[i][j] = 2;
}
// void debug() {
//      for (int i = 1; i <= n; i++) {
//                 for (int j = 1; j <= m; j++) cout << big[i][j] << " ";
//                 cout << endl;
//              }
//     cout << "----------------" << endl;
// }
void dp(int i, int j) {
    if (big[i][j]) return;
    big[i][j] = 1;
    int x = i, y = j;
    getNext(x, y, dir[x][y]);
    if (!check(x, y)) return;
    dp(x, y);
    big[i][j] = big[x][y] + 1;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> dir[i][j];
            color[i][j] = 0; big[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (color[i][j]) continue;
            dfs(i, j);
            // debug();
           
        }
    }
    int d = -1; pii res = {-1, -1};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {         
            if (big[i][j]) continue;
            dp(i, j);
 
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (big[i][j] > d) {
                d = big[i][j];
                res = {i, j};
            }
        }
    }
    // debug();
    cout << res.first << " " << res.second <<" " <<  d << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
