#include <bits/stdc++.h>
#define int ll
#define ll long long
#define pp pair<int, int>

const int N = 251 * 251 + 1;

using namespace std;

int n, m, a[N], b[N];
vector<pp>  points;
vector<int> res;
void solve() {
    int t;
    cin >> t >> n >> m; n++, m++;
    map<int, int> coor1, coor2;
    for (int i = 1; i <= n; i++) cin >> a[i], coor1[a[i]] = i;
    for (int j = 1; j <= m; j ++) cin >> b[j], coor2[b[j]] = j;
    for (auto v : coor1) {
        if (coor2.find(v.first) == coor2.end()) continue;
        points.push_back({v.second, coor2[v.first]});
    }
    sort(points.begin(), points.end());
    vector<int> b; for (auto v : points) b.push_back(v.second);
    for (auto v : b) {
        auto it = lower_bound(res.begin(), res.end(), v);
        if (it == res.end()) res.push_back(v);
        else *it = v;
    }
    cout << res.size() << "\n";
    res.clear(); points.clear();

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase; cin >> testcase; 
    for (int t = 1; t <= testcase; t++) {
        cout << "Case" << " " << t << ": "; 
        solve();
    }
    
   
}