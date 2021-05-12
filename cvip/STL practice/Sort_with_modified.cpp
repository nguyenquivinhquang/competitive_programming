//uva 612
#include <bits/stdc++.h>
#define pp pair<string, int>
const int N = 105;
using namespace std;
struct dt {
    string str;
    int index, inv;
    void set(string s, int invs, int ind) {
        str = s, inv = invs, index = ind;
    }
} ;
int n, m;
string a[N];
vector<dt> sq;
unordered_map<char, int> cond;
int compute_inversions(string &str) {
    int inversions = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (cond[str[j]] < cond[str[i]]) inversions++;
    return inversions;
}
bool cmp(dt &x, dt &y) {
    if (x.inv != y.inv) return x.inv < y.inv;
    return x.index < y.index;
}
void compute_inversions() {
    sq.clear();
    sq.resize(m);
    for (int i = 1; i <= m; i++) {
       int inv = compute_inversions(a[i]);
       sq[i - 1].set(a[i], inv, i); 
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    compute_inversions();
    sort(sq.begin(), sq.end(), cmp);
    for (auto x : sq) {
        cout << x.str << "\n";
    }
}   
signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cond['A'] = 1, cond['C'] = 2, cond['G'] = 3, cond['T'] = 4;
    cin >> testcase;
    while (testcase--) {
        solve();
        if (testcase) cout << "\n";
    }
}