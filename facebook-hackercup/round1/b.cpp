#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 2000;
int cond[N][N];
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int a[N][N];
void solve() {
    memset(a, 0, sizeof(a));
    int n, m, A, B;
    cin >> n >> m >> A >> B;
    if (n + m - 1 > A || n + m - 1 > B ) {
        cout << "Impossible\n";
        return;
    } 
    cout << "Possible\n";
    int sum = 0;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) a[i][j] = 1;
    for (int j = 1; j <= m; j++) a[n][j] = 2;

    a[n][m] = A - n - m + 1 + 1;
    a[n][1] = B - n - m + 1 + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!(i != 1 && i != n && j  != 1 && j != m))
                cout << a[i][j] << " ";
            else cout << "2 ";
        }
        cout << "\n";
    }
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test; cin >> test;

    for (int t = 1; t <= test; t++) {
        cout << "Case " << "#" << t << ": "; solve();
    }
}
