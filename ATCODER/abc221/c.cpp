#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, m;
char a[N][N];
vector<int> step;
int trace[N];
bool cmp(int x, int y) {
    if (trace[x] == trace[y]) return x < y;
    return trace[x] > trace[y];
}
int win(char x, char y) {
    if (x == 'G' && y == 'C') return 1;
    if (x == 'C' && y == 'P') return 1;
    if (x == 'P' && y == 'G') return 1;
    if (x == y) return 0;
    return -1;
}
void solve() {
    cin >> n >> m;
    n *= 2;
    for (int i =1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
        step.push_back(i);
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j +=2) {
            int x = step[j], y = step[j + 1];
            int is_win = win(a[x][i], a[y][i]);
            if (is_win == 1) trace[x]++;
            else if (is_win == -1) trace[y]++;

        }
        sort(step.begin(), step.end(), cmp);
    }
    for (auto v : step) {
        cout << v << "\n";
    }
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1;
//    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
