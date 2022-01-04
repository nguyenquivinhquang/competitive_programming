
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 200009;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, m;
// set<pair<int, pii>> trace;
vector<int> a[N], pos[N];
set<int, greater<int>> trace;

int id[N], color[N], fitst_pos[N];
void add(int c, int i) {
    pos[c].push_back(i);
    color[c]++;
    if (color[c] == 2) trace.insert(c);
}
void solve() {
    memset(color, 0, sizeof(color));
    cin >> n >> m;
    for (int j = 1; j <=m; j++) {
        cin >> id[j];
        for (int i = 1; i <= id[j]; i++) {
            int temp;
            cin >> temp;
            a[j].push_back(temp);
        }
        reverse(a[j].begin(), a[j].end());
    }
    for (int i = 1; i <= m; i++) {
        if (a[i].size() ==0) continue;
        int cur = a[i].back();
        add(cur, i);
        a[i].pop_back();
    }
    
        while(trace.size()) {
            int cur = *trace.begin(); trace.erase(trace.begin());
            int x = pos[cur][0], y = pos[cur][1];
            if (a[x].size()) {
                add(a[x].back(), x);
                a[x].pop_back();
            }
            if (a[y].size()) {
                add(a[y].back(), y);
                a[y].pop_back();
            }
        }
    
    for (int i = 1; i <= m; i++)
        if (a[i].size()) {
            cout << "No";
            return;
        }
    cout << "Yes";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    // cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
