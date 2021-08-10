#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1005;

using namespace std;
bool cmp(pp x, pp y) {
    if (x.first == y.first) return x.second < y.second;
    return x.first < y.first;
}
int n, m;
vector<pp> coor;
string path;
bool visited[N][N];
void create_path(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1, dy = y2 - y1, x = x1, y = y1;
    // 2 corner
    if (dy == 1) {
        if (visited[x][y+1] == true) {
            path = path + 'R';
            visited[x][y+1] = false;
            while (dx--) path.push_back('D'), visited[++x][y+1] = false; 
            return;
        }
        if (visited[x+1][y] == true) {
            visited[x+1][y] = false;
            while (dx--) path.push_back('D'), visited[x+1][++y] = false;
            path.push_back('R');
            return;
        }
    }
    // at same row;
    if (x1 == x2) while (dy--) path.push_back('R');
    // at same col
    if (y1 == y2) while (dx--) path.push_back('D');

    if (dx <= 0 && dy <= 0) return;
    int mid = (y1 + y2) / 2;
    for (; y1 < mid; y1++) path.push_back('R'), visited[x1][y1] = false;
    for (; x1 < x2; x1++) path.push_back('D'), visited[x1][mid] = false;
    for (y1; y1 < y2; y1++) path.push_back('R'), visited[x2][y1] = false;


}
void get_jury() {
    int q, x, y;
    cin >> q;
    coor.clear();
    while (q--) {
        cin >> x >> y;
        coor.push_back({x,y});
        visited[x][y] = true;
    }
}
signed main() {
    // ios_base::sync_with_stdio(false), cin.tie(NULL);
    memset(visited, true, sizeof(visited));
    cin >> n >> m;
    coor.push_back({1,1}); coor.push_back({n,m});
    for (int query = 1; query <= 11; query++) {
        path = "";
        sort(coor.begin(), coor.end(), cmp);
        for (int i = 0; i < coor.size() -1; i++) {
            auto u = coor[i], v = coor[i+1];
            create_path(u.first, u.second, v.first, v.second);
        }
        if (query == 11) continue;
        cout << "? " << path << endl;
        get_jury();
    }
    cout << "! " << path << endl;
}
