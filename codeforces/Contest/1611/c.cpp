#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 200009;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, a[N];
void solve() {
    cin >> n;
    int Max = -1, idx = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > Max) {
            Max = a[i];
            idx = i;
        }
    }
    if (idx != 1 && idx != n) cout << -1;
    else {
        if (idx == 1) {
            cout << a[1] << " ";
            for (int i = n; i >=2; i--) cout << a[i] << " ";
            
        } else {
            
            for (int i = n-1; i >= 1; i--) cout << a[i] << " ";
            cout << a[n] << " ";
        }
    }
    cout << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
