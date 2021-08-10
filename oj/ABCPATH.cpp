#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 55;

using namespace std;
char a[N][N];
bool fee[N][N];
int n, m;
int res = 0;
bool check(char C, char nextC) {
    if (nextC - 'A' < 0 || nextC - 'A' > 'Z' - 'A' ) return false;
    return nextC - C == 1;
}
void dfs(int u, int v, int curDistance) {
    fee[u][v] = false;
    res = max(res, curDistance);
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++) {
            if (u + i > n || u + i < 1 || v + j > m || v + j < 1) continue;
            if (check(a[u][v], a[u + i][v + j]) && fee[u + i][v + j])
                dfs(u + i, v + j, curDistance + 1);
        }

}
void solve() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            fee[i][j] = true;
        }
    res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 'A') dfs(i, j ,1);
    cout << res << "\n";

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int totalTestcase = 0;
    while (cin >> n >> m) {
        if (n == 0 && m == 0)  break;
        totalTestcase++;
        cout << "Case " << totalTestcase << ": ";
        solve();
    }
}
