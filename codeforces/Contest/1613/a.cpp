#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int getLength(int x) {
    int i = 0;
    while(x > 0) {
        i++;
        x/=10;
    }
}
void solve() {
    int x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    if (getLength(x1) + p1 != getLength(x2) + p2) {
        if (getLength(x1) + p1 > getLength(x2) + p2) cout << ">";
        else cout << "<";
    } {
        
    }
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
