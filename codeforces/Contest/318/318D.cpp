#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1500;
int coor[N][N];
int n; // n = ants
void solve() {
    queue<pii> q;
    q.push({500, 500});
    while (q.size() != 0) {
        pii cur = q.front(); q.pop();
        int x = cur.first, y = cur.second ;
        if (coor[x][y] >= 4) {
            coor[x][y] -=4;
            if (coor[x][y] >= 4) q.push({x, y});
            coor[x + 1][y]++, coor[x - 1][y]++, coor[x][y + 1]++, coor[x][y - 1]++;
            q.push({x, y + 1}), q.push({x + 1, y}), q.push({x - 1, y}), q.push({x, y - 1});\           
        }
    }
}
signed main() {
   ios::sync_with_stdio(false), cin.tie(NULL);
   cin.exceptions(cin.failbit);
    int query, x, y;
    cin >> n >> query;
    coor[500][500] = n;
    solve();
    while (query--) {
        cin >> x >> y;
        if (abs(x) > 500 || abs(y) > 500) cout <<0;
        else cout << coor[x + 500][y + 500];
        cout << "\n";
    }
}
