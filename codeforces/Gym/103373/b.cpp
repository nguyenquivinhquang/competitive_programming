#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000020;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int trace[N + 10];
void solve() {
    // trace[1] = 1;
    for (int i = 1; i < N - 1; i++) {
        // if (trace[i] == 0) trace
        for (int j = i+i; j < N - 1; j += i ) {
            trace[j] += i;
        }
        // cout << i << " " << trace[12] << "\n";
    }
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    solve();
    // cout << trace[2] << "\n";
    // for (int i = 1; i <= 15; i++) cout << trace[i] - 1<< " ";
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
         int n; cin >> n;
         if (trace[n] > n) cout << "abundant";
         else if (trace[n] == n) cout << "perfect";
         else cout << "deficient";
         cout << "\n";
    }
}
