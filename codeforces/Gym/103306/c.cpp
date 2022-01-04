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
    string str; cin >> str;
    int B = 0, R = 0;
    queue<pair<char, int> > q;
    int res = 0;
    for (int i = 0; i < str.size(); i++) {
        char v = str[i];
        if (v == 'B') B++;
        else R++;
        q.push({v, i+1});

        while(q.size() && R > B) {
            auto c = q.front(); q.pop();
            res = c.second;
            if (c.first == 'B') B--; else R--;
        }
    }
    cout << res << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
