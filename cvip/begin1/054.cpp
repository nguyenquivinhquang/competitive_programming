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
    ll a,b,res;
    cin >> a >> b;
    int j = sqrt(max(a, b)) + 1;
    if (a % b == 0 || b % a == 0) {
        cout << min(a, b);
        return 0;
    }
    for (; j >= 1; j--) {
        if (a % j == 0 && b % j ==0) {
            cout << j;
            return 0;
        }
    }
}
