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

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        string a, b;
        cin >> a >> b;
        if (a > b) cout << 1;
        else if (a==b) cout <<0;
        else cout << -1;
        cout << "\n";
    }
}
