#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;
int cond[N][N];
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
string str;
map<int,int> ans;
vector<int> rows, columns;
int n;
char a[N][N];
void solve() {
    ans.clear(); rows.clear(), columns.clear();
    cin >> n; rows.resize(n + 3); columns.resize(n + 3);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'O') {
                rows[i] = 1;
                columns[j] = 1;
            }
        }
    }
    bool check = true; int cur = 0, res = 1e9;
    // for (int i = 1; i <= n; i++) {
    //     if (a[i][i]=='O') {
    //         check = false;
    //         break;
    //     }
    //     if (a[i][i] == 'X') continue;
    //     cur++;
    // }
    // if (check) res = cur, ans[res]++;
    vector<vector<pii>> trace;
    for (int i = 1; i <= n; i++) {
        if (columns[i] == 0) {
            vector<pii> temp;
            // cout << "col " << i << endl;
            int cur = 0;
            for (int j = 1; j <= n; j++) {
                if (a[j][i] == 'X') continue;
                temp.push_back({j,i});
                cur++;
            }
            res = min(res, cur);
            sort(temp.begin(), temp.end());
            trace.push_back(temp);
        }
        if (rows[i] == 0) {
            int cur = 0;
            vector<pii> temp;
            // cout << "row " << i << endl;
            for (int j = 1; j <= n; j++) {
                if (a[i][j] == 'X') continue;
                temp.push_back({i,j});
                cur++;
            }
            res = min(res, cur);
            sort(temp.begin(), temp.end());
            trace.push_back(temp);
        }
    }
    if (res == 1e9) {
        cout << "Impossible\n";
        return;
    }
    vector<vector<pii>> temp;
    for (auto v : trace) {
        if (v.size() == res) temp.push_back(v);
    }
    sort(temp.begin(), temp.end());
    int sl = 1;
    for (int i = 1; i < temp.size(); i++) {
        if (temp[i].size() != res) break;
        if (temp[i] != temp[i-1]) sl++;
    }
    
    cout <<res << " " << sl;
    cout << "\n";
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
