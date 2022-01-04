#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int p, q;
ll Pow(int x, int y) {
    int res = 1;
    for (int i = 1; i <= y; i++) res *= x;
    return res;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> p >> q;
    int x = 0;
    for (int i = 1; i <= 200; i++) {
        x -= p;
        if (p < q  * i * i * i *i * i) break;
        x += q  * i * i * i *i * i;
    }
    cout << x;
}
