#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
const int N = 4000000;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
long long  prefix[N];
void solve() {
    int res = 0;
    ll a, b, x;
    cin >> a >> b;
    if (a != 0) res = prefix[a-1];

    ll cur  = b ^ res;
    if (cur == 0 && b == 0) {
        cout << a << "\n";
        return;
    }
    if (cur == a) a += 2;
    else if (cur != 0) a += 1;
    
    cout << a << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    prefix[0] = 0;
    for (int i = 1; i <= 400000; i++) 
        prefix[i] = prefix[i-1] ^ i;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}