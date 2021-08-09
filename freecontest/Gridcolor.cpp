#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1005;

using namespace std;

int n, m, k;
char h[N][N], v[N][N];
int res[N][N];
bool check() {
    double total = 0.0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < m; j++)
            if (h[i][j] == 'E' && res[i][j] == res[i][j + 1] || h[i][j] == 'N' && res[i][j] != res[i][j + 1])
                total++;
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= m; j++)
            if (v[i][j] == 'E' && res[i][j] == res[i + 1][j] || v[i][j] == 'N' && res[i][j] != res[i + 1][j])
                total++;
    double ss = (n * (m - 1.0)) + (n - 1.0) * m;
    double err = total / ss ;
    if (err >= 0.7500) return true;
    return false;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
     srand(time(NULL));
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < m; j++)
            cin >> h[i][j];
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= m; j++)
            cin >> v[i][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (k != 1)
            res[i][j] = rand() % min(k, 3) + 1; else res[i][j] = 1;
        }
    }
    // if (check()) {
    if (k == 1)
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
    else cout << -1;
    // } else
        // cout << -1;
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/