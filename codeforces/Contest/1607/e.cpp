#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void solve() {
    int x, y, n, m, minX, minY, maxX, maxY, ansX, ansY = 1;
    string cm;
    x = y = 0;
    minX = minY = maxX = maxY = 0;
    ansX = ansY = 1;
    cin >> n >> m;
    cin >> cm;
    for (auto v : cm) {
        if (v == 'L') y--;
        if (v == 'R') y++;
        if (v == 'U') x--;
        if (v == 'D') x++;
        minX = min(minX, x); minY = min(minY, y);
        maxX = max(maxX, x); maxY = max(maxY, y);
        if (abs(minX - maxX) >= n || abs(minY - maxY) >= m) break;
        ansX = 1 - minX;
        ansY = 1 - minY;
    }
    cout << ansX << " " << ansY << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
