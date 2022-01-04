#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 100;
int cond[N][N], dp[N][N];
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
string str; int n;
map<char,int> vowels;
void reset() {
    for (char k = 'A'; k <= 'Z'; k++) 
        for (char x = 'A'; x <= 'Z'; x++) 
            if (k != x) cond[k-'A'][x-'A'] = 1e9;
            // else cond[k][x] = 0;
}
int brute(char an) {
    int step = 0;
    for (auto c : str) {
        if (c == an) continue;
        if (cond[c-'A'][an - 'A'] != 1e9) step+=cond[c-'A'][an - 'A'];
        else return -1;

    }
    return step;
}
void build_graph() {
    for (char k = 'A'; k <= 'Z'; k++) {
        for (char x = 'A'; x <= 'Z'; x++) {
            for (char y = 'A'; y <= 'Z'; y++)    {
                cond[x - 'A'][y -'A'] = min(cond[x - 'A'][y-'A'], cond[x - 'A'][k - 'A'] + cond[k - 'A'][y - 'A']);
            }
        }

    }
}
void solve() {
    reset();
    cin >> str >> n;
    for (int i = 1; i <= n; i++) {
        char x, y; cin >> x >> y;
        cond[x - 'A'][y - 'A'] = 1;
    }
    build_graph();
    int res = 1e9;
    for (char c = 'A'; c <= 'Z'; c++){
        int val = brute(c);
        if (val == -1) continue;
        res = min(res, val);

    }
    if (res == 1e9) res = -1;
    cout << res << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test; cin >> test;
    vowels['A'] = 1; vowels['E'] = 1, vowels['O'] = 1; vowels['I'] = 1; vowels['U'] = 1;

    for (int t = 1; t <= test; t++) {
        cout << "Case " << "#" << t << ": "; solve();
    }
}
