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
    string x,  str; int y;
    bool check = true;
    cin >> str;
    for (auto c : str) {
        if (c == '.') {
            check = false;
            continue;
        }
        if (check == true) x.push_back(c);
        else y = c -'0';
    }
    cout << x;
    if (0 <= y && y <= 2) cout <<'-';
    else if (7 <= y && y <= 9) cout << "+";
    
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    // cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
