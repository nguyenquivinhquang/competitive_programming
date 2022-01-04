#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000009;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, a[N], b[N], d;
void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    bool check = false;
    int c = 0;
    for (int i =1 ; i <= n; i+=1) {
        if (a[i] == b[i]){
            c++;
            continue;
        }
        if (i - 1 < d && n - i < d) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
