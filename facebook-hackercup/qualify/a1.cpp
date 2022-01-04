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
map<char,int> vowels;
int brute(char an) {
    int step = 0;
    for (auto c : str) {
        if (c == an) continue;
        if (vowels[c] != vowels[an]) step+=1;
        else step += 2;
    }
    return step;
}
void solve() {
    cin >> str;
    int res = 1e5;
    for (char c = 'A'; c <= 'Z'; c++) res = min(res, brute(c));
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
