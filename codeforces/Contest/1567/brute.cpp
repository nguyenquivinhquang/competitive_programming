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
    int a, b, pre = 0;
    cin >> a >> b;
    for (int i = 1; i < a; i++) pre ^= i;
    
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    solve();
}
